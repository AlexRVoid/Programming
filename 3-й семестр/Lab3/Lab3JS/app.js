const v8 = require('v8');
const util = require('util');
let fs = require('fs');
let fs1 = require('fs');
let fs2 = require('fs');
//const xml2js = require('xml2js');


class Product {
    product;
    productid;
    warehousecell;
    productquantity;
    constructor(product, product_id, warehouse_cell, product_quantity) {
        this.product = product;
        this.productid = product_id;
        this.warehousecell = warehouse_cell;
        this.productquantity = product_quantity;
    }
}

const product = new Product("water", "89", "B3", 500);
console.log(product);
const jprod = JSON.stringify(product);
fs.writeFileSync('JsonSerialization.json', jprod);
const product1 = JSON.parse(fs.readFileSync('JsonSerialization.json', 'utf8'));
console.log(product1);
const binprod = v8.serialize(product);
fs1.writeFileSync('BinarySerialization.dat', binprod);
console.log(binprod);
const builder = new xml2js.Builder();
const xml = parser.buildObject(product);
console.log(xml);
fs2.writeFileSync('XMLSerialization.xml', xml);
console.log(product1);