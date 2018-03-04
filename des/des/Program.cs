using System;
using System.IO;
using System.Security.Cryptography;//存des类的命名空间

namespace TripleDESCryptoServiceProvider_Example
{
    class TripleDESManagedExample
    {
        public static void Main()
        {
            try
            {
                //测试数据
                string original = "Here is some $%^dfg5687 data to encrypt!";

                // TripleDESCryptoServiceProvider是des算法的加密提供服务程序，实例化一个对象
                // 会产生一个密钥和改算法的初始化向量
                using (TripleDESCryptoServiceProvider myTripleDES = new TripleDESCryptoServiceProvider())
                {
                    // 加密并返回数据，传入参数为明文，密钥，和初始化向量
                    byte[] encrypted = EncryptStringToBytes(original, myTripleDES.Key, myTripleDES.IV);

                    // 解密并返回数据，传入参数为密文，密钥，和初始化向量
                    string roundtrip = DecryptStringFromBytes(encrypted, myTripleDES.Key, myTripleDES.IV);

                    //Display the original data and the decrypted data.
                    Console.WriteLine("明文:   {0}", original);
                    Console.WriteLine("密文:   {0}", BitConverter.ToString(encrypted));
                    Console.WriteLine("解密后的明文: {0}", roundtrip);
                }

            }
            catch (Exception e)
            {
                Console.WriteLine("Error: {0}", e.Message);
            }
        }

        //加密算法
        static byte[] EncryptStringToBytes(string plainText, byte[] Key, byte[] IV)
        {
            // 检查传入的参数是否有效
            if (plainText == null || plainText.Length <= 0)
                throw new ArgumentNullException("plainText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("Key");
            byte[] encrypted;
            //string encryped;
            // TripleDESCryptoServiceProvider是des算法的加密提供服务程序，实例化一个对象
            // 会产生一个密钥和改算法的初始化向量，此处接收传进来的密钥和向量
            using (TripleDESCryptoServiceProvider tdsAlg = new TripleDESCryptoServiceProvider())
            {
                tdsAlg.Key = Key;
                tdsAlg.IV = IV;

                // 使用密钥和初始化向量创建加密器对象
                ICryptoTransform encryptor = tdsAlg.CreateEncryptor(tdsAlg.Key, tdsAlg.IV);

                // 创建在内存中的流用来保存密文，初始为空
                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    //将用来保存密文的流链接到加密转换的流，加密流指定特定模式为写
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        //关键步骤，以特定编码向加密流写入字符，特定编码为des加密后的编码
                        using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                        {
                            swEncrypt.Write(plainText);
                        }
                        //将密文转化为数组
                        encrypted = msEncrypt.ToArray();
                        //encryped = msEncrypt.ToString();
                    }
                }
            }

            //Console.WriteLine();
            //从内存中返回密文
            return encrypted;

        }

        static string DecryptStringFromBytes(byte[] cipherText, byte[] Key, byte[] IV)
        {
            // 检查传入的参数是否有效
            if (cipherText == null || cipherText.Length <= 0)
                throw new ArgumentNullException("cipherText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("Key");

            //用来存储解密后的明文
            string plaintext = null;

            // TripleDESCryptoServiceProvider是des算法的加密提供服务程序，实例化一个对象
            // 会产生一个密钥和改算法的初始化向量，此处接收传进来的密钥和向量
            using (TripleDESCryptoServiceProvider tdsAlg = new TripleDESCryptoServiceProvider())
            {
                tdsAlg.Key = Key;
                tdsAlg.IV = IV;

                // 使用密钥和初始化向量创建加密器对象
                ICryptoTransform decryptor = tdsAlg.CreateDecryptor(tdsAlg.Key, tdsAlg.IV);

                // 创建在内存中的流用来保存密文，初始里面存储密文
                using (MemoryStream msDecrypt = new MemoryStream(cipherText))
                {
                    //将用来保存密文的流链接到解密转换的流，解密流指定特定模式为读
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                    {
                        //关键步骤，以特定编码从解密流读出所有字符
                        using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                        {
                            plaintext = srDecrypt.ReadToEnd();
                        }
                    }
                }

            }
            //返回解密后的明文
            return plaintext;

        }
    }
}