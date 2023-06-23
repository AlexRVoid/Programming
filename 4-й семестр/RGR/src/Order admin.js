const TelegramBot = require('node-telegram-bot-api');
const fs = require('fs');
const path = require('path');


// Токен вашего бота, полученный от BotFather
const token = '6100351907:AAGDnfTFiWfe2rSp-MKKdaEohLUS_JoNlI8';


// Путь к файлу заказов в папке проекта
const ordersFilePath = path.join(__dirname, 'orders.txt');

// Создание экземпляра бота
const bot = new TelegramBot(token, { polling: true });

// Обработчик команды /start
bot.onText(/\/start/, (msg) => {
    const chatId = msg.chat.id;
    bot.sendMessage(
        chatId,
        'Добро пожаловать! Чтобы сделать заказ, введите /order <текст заказа>. Чтобы закрыть заказ, введите /close <ID заказа>. Чтобы посмотреть список заказов, введите /list'
    );
});

// Обработчик команды /order
bot.onText(/\/order (.+)/, (msg, match) => {
    const chatId = msg.chat.id;
    const orderText = match[1];
    const orderId = generateOrderId(); // Генерация уникального ID заказа

    // Сохранение заказа в файл
    fs.appendFile(
        ordersFilePath,
        `OPEN: ${orderId}: ${chatId}: ${orderText}\n`,
        (err) => {
            if (err) {
                console.error(err);
                bot.sendMessage(chatId, 'Произошла ошибка при сохранении заказа.');
            } else {
                bot.sendMessage(chatId, 'Заказ сохранен. ID заказа: ' + orderId);
            }
        }
    );
});

// Обработчик команды /close
bot.onText(/\/close (.+)/, (msg, match) => {
    const chatId = msg.chat.id;
    const orderId = match[1];

    // Чтение файла заказов
    fs.readFile(ordersFilePath, 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            bot.sendMessage(chatId, 'Произошла ошибка при чтении заказов.');
        } else {
            const orders = data.trim().split('\n');
            let foundOrder = false;

            for (let i = 0; i < orders.length; i++) {
                const order = orders[i];
                const orderData = order.split(':');
                const orderStatus = orderData[0].trim();
                const existingOrderId = orderData[1].trim();

                if (orderStatus === 'OPEN' && existingOrderId === orderId) {
                    const updatedOrder = order.replace('OPEN', 'CLOSED');

                    orders[i] = updatedOrder;
                    foundOrder = true;
                    break;
                }
            }

            if (!foundOrder) {
                bot.sendMessage(
                    chatId,
                    'Заказ с указанным ID не найден или уже закрыт.'
                );
                return;
            }

            // Обновление файла заказов
            fs.writeFile(ordersFilePath, orders.join('\n'), 'utf8', (err) => {
                if (err) {
                    console.error(err);
                    bot.sendMessage(chatId, 'Произошла ошибка при закрытии заказа.');
                } else {
                    bot.sendMessage(
                        chatId,
                        'Заказ успешно закрыт. ID заказа: ' + orderId
                    );
                }
            });
        }
    });
});

// Обработчик команды /list
bot.onText(/\/list/, (msg) => {
    const chatId = msg.chat.id;

    // Чтение файла заказов
    fs.readFile(ordersFilePath, 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            bot.sendMessage(chatId, 'Произошла ошибка при чтении заказов.');
        } else {
            const orders = data.trim().split('\n');
            const openOrders = orders.filter((order) => order.includes('OPEN'));

            if (openOrders.length === 0) {
                bot.sendMessage(chatId, 'Нет доступных заказов.');
            } else {
                bot.sendMessage(chatId, 'Список заказов:\n' + openOrders.join('\n'));
            }
        }
    });
});

// Запуск бота
bot.on('polling_error', (error) => {
    console.error(error);
});

// Генерация уникального ID заказа
function generateOrderId() {
    return Math.random().toString(36).substr(2, 10);
}