const express = require('express');
const fs = require('fs');
const path = require('path');

const app = express();
const port = 3001;

app.get('/api/orders', (req, res) => {
    const ordersFilePath = path.join(__dirname, 'orders.txt');

    fs.readFile(ordersFilePath, 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            res.status(500).send('Error reading orders file');
        } else {
            const ordersData = data.trim().split('\n');
            const parsedOrders = ordersData.map((order) => {
                const orderInfo = order.split(':');
                return {
                    status: orderInfo[0].trim(),
                    orderId: orderInfo[1].trim(),
                    userId: orderInfo[2].trim(),
                    orderText: orderInfo[3].trim(),
                    phoneNumber: orderInfo[4].trim(),
                };
            });
            res.json(parsedOrders);
        }
    });
});

app.listen(port, () => {
    console.log(`Server running on port ${port}`);
});
