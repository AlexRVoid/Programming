using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace Lab3Sharp
{
    public partial class MainWindow : Form
    {
        
        public MainWindow()
        {
            InitializeComponent();
            Serialization_Type.Items.AddRange(new string[] { "Binary", "XML", "JSON"});
            Serialization_Type.SelectedItem = Serialization_Type.Items[0];
            Deserialization_Type.Items.AddRange(new string[] { "Binary", "XML", "JSON" });
            Deserialization_Type.SelectedItem = Deserialization_Type.Items[0];
            ClearInput();

        }

        public void ClearInput()
        {
            product_info.Clear();
            product_id_info.Clear();
            warehouse_cell_info.Clear();
            product_quantity_info.Clear();
        }

        private void Add_product_Click(object sender, EventArgs e)
        {
            Product product = new Product(product_info.Text, product_id_info.Text, warehouse_cell_info.Text, product_quantity_info.Text);
            Add(product);
            
        }
        

        private void listProduct_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listProduct.SelectedItems.Count == 1)
            {
                Product product = (Product)listProduct.SelectedItems[0].Tag;
                if (product != null)
                {
                    product_info.Text = product.product;
                    product_id_info.Text = product.product_id;
                    warehouse_cell_info.Text = product.warehouse_cell;
                    product_quantity_info.Text = Convert.ToString(product.product_quantity);
                }
            }
            else if (listProduct.SelectedItems.Count == 0)
            {
                ClearInput();
            }
        }

        private void Serialize_Click(object sender, EventArgs e)
        {
            Serialization serialization = new Serialization();
            Products products = new Products();
            if (Serialization_Type.SelectedItem.ToString() == "XML")
            {
                foreach(ListViewItem item in listProduct.Items)
                {
                    products.products.Add((Product)item.Tag);
                }
                serialization.XML_Serialization(products);
            }
            if (Serialization_Type.SelectedItem.ToString() == "Binary")
            {
                foreach (ListViewItem item in listProduct.Items)
                {
                    products.products.Add((Product)item.Tag);
                }
                serialization.Binar_Serialization(products);
            }
            if (Serialization_Type.SelectedItem.ToString() == "JSON")
            {
                foreach (ListViewItem item in listProduct.Items)
                {
                    products.products.Add((Product)item.Tag);
                }
                serialization.JSON_Serialization(products);
            }
        }

        private void Add (Product product)
        {
            ClearInput();
            ListViewItem LVI = new ListViewItem(product.product);
            LVI.Tag = product;
            listProduct.Items.Add(LVI);
        }
        private void Deserialize_Click(object sender, EventArgs e)
        {
            Deserialization deserialization = new Deserialization();
            Products products = new Products();
            if (Deserialization_Type.SelectedItem.ToString() == "XML")
            {
                ClearInput();
                products = deserialization.XML_Deserialization();
                foreach (Product product in products.products) 
                { 
                    Add(product);
                }
            }
            if (Deserialization_Type.SelectedItem.ToString() == "Binary")
            {
                ClearInput();
                products = deserialization.Binar_Deserialization();
                foreach (Product product in products.products)
                {
                    Add(product);
                }
                
            }
            if (Deserialization_Type.SelectedItem.ToString() == "JSON")
            {
                ClearInput();
                products = deserialization.JSON_Deserialization();
                foreach (Product product in products.products)
                {
                    Add(product);
                }
            }
        }

        private void MainWindow_Load(object sender, EventArgs e)
        {

        }
    }
}