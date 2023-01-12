using Microsoft.VisualBasic.ApplicationServices;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Lab3Sharp
{
    [Serializable]
    public class Product
    {
        public string product = "";
        public string product_id = "";
        public string warehouse_cell = "";
        public int product_quantity;

        public Product() { }
        public Product(string product, string product_id, string warehouse_cell, string product_quantity)
        {
            this.product = product;
            this.product_id = product_id;
            this.warehouse_cell = warehouse_cell;
            this.product_quantity = Convert.ToInt32(product_quantity);
        }
        
    }

    [Serializable]
    public class Products
    {
        public List <Product> products = new List <Product> ();
        public Products() { }
    }
    public class Serialization: Products
    {
        public void Binar_Serialization(Products products)
        {
            BinaryFormatter formatter = new BinaryFormatter();

            using (FileStream fs = new FileStream("Binar_Serialization.dat", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, products);

            }
            MessageBox.Show("Binary serialization was successful");
        }
        public void XML_Serialization(Products products)
        {
            XmlSerializer writer = new XmlSerializer(typeof(Products));

            using (FileStream fs = new FileStream("XMLSerialize.xml", FileMode.OpenOrCreate))
            {
                writer.Serialize(fs, products);
            }
            MessageBox.Show("XML serialization was successful");
        }

        public void JSON_Serialization(Products products)
        {
            //string jsonString = JsonSerializer.Serialize(products);

            //File.WriteAllText("JSON_Serialization.json", jsonString);


            FileStream file3 = new FileStream("JSON_Serialization.json", FileMode.OpenOrCreate);
            StreamWriter stream = new StreamWriter(file3);
            for (int i = 0; i < products.products.Count; i++)
            {
                string json1 = JsonSerializer.Serialize(products.products[i]);
                stream.WriteLine(json1);
            }
            stream.Close();
            file3.Close();



            MessageBox.Show("JSON serialization was successful");
        }
    }
    public class Deserialization: Products
    {
        public Products Binar_Deserialization()
        {
            BinaryFormatter formatter = new BinaryFormatter();

            using (FileStream fs = new FileStream("Binar_Serialization.dat", FileMode.OpenOrCreate))
            {
                MessageBox.Show("Binar deserialization was successful");
                return (Products)formatter.Deserialize(fs);

            }
        }
        public Products XML_Deserialization()
        {
            XmlSerializer xml = new XmlSerializer(typeof(Products));
            

            using (FileStream fs = new FileStream("XMLSerialize.xml", FileMode.OpenOrCreate))
            {
                MessageBox.Show("XML deserialization was successful");
                Products? products = xml.Deserialize(fs) as Products;
                return products;
            }
        }

        public Products JSON_Deserialization()
        {
            Products products = new Products();
            StreamReader f = new StreamReader("JSON_Serialization.json");
            while (!f.EndOfStream)
            {
                string s = f.ReadLine();
                products.products.Add(JsonSerializer.Deserialize<Product>(s));
            }
            f.Close();

            return products;
        }
    }
}
