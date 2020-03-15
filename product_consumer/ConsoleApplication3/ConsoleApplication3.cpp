

#include <iostream>
#include <mutex>
#include <thread>
#include <queue>
#include <atomic>

#define MAX_QUEUE_SIZE 10

class Test
{
public:
	Test();
	~Test();

	void product(int num);
	void consumer();
	int stop();
private:
	std::mutex mutex_;
	// 如果是消费者生产者平衡的关系，则可考虑使用条件变量控制，减少CPU消耗
	std::condition_variable cv_pro_;
	std::condition_variable cv_com_;
	std::atomic<bool> b_flag_;
	std::queue<int> queue_;
};

Test::Test() : b_flag_(false)
{
}

Test::~Test()
{
}

void Test::product(int num)
{
	while (true) {
		std::unique_lock<std::mutex> lock(mutex_);
		if (b_flag_) {
			return;
		}
		if (queue_.size() < MAX_QUEUE_SIZE) {
			std::cout << "num: " << num << std::endl;
			queue_.push(num);
		}
		// 需要主动释放锁，否则可能会造成另一个线程执行不及时的问题
		lock.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void Test::consumer()
{
	while (true) {
		std::unique_lock<std::mutex> lock(mutex_);
		if (b_flag_) {
			return;
		}
		if (queue_.empty()) {
			lock.unlock();
			continue;
		}

		std::cout << "num2: " << queue_.front() << std::endl;
		queue_.pop();
		// 需要主动释放锁，否则可能会造成另一个线程执行不及时的问题
		lock.unlock();
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

int Test::stop()
{
	b_flag_ = true;
	return 0;
}

int main(int argc, char** argv)
{
	Test test;
	std::thread push_thread(std::mem_fn(&Test::product), std::ref(test), 10);
	std::thread pop_thread(std::mem_fn(&Test::consumer), std::ref(test));

	getchar();
	test.stop();
	push_thread.join();
	pop_thread.join();
	return 0;
}

