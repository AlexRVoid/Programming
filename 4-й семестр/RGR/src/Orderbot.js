const TelegramBot = require('node-telegram-bot-api');
const fs = require('fs');
const path = require('path');
const { v4: uuidv4 } = require('uuid');

// Токен вашего бота, полученный от BotFather
const token = '6239041673:AAGfUhZTyYUupwFRJHUKLaKL-VjsyPqH9SQ';


// Путь к файлу заказов в папке проекта
const ordersFilePath = path.join(__dirname, 'orders.txt');

// Создание экземпляра бота
const bot = new TelegramBot(token, { polling: true });

// Обработчик команды /start
bot.onText(/\/start/, (msg) => {
    const chatId = msg.chat.id;
    bot.sendMessage(
        chatId,
        'Добро пожаловать! Чтобы сделать заказ, введите /order <текст заказа>. Чтобы закрыть заказ, введите /close <ID заказа>.'
    );
});

// Обработчик команды /order
bot.onText(/\/order (.+)/, (msg, match) => {
    const chatId = msg.chat.id;
    const orderText = match[1];
    const orderId = uuidv4(); // Генерация уникального ID заказа
    const userId = msg.from.id; // Получение номера пользователя

    // Запрос номера телефона
    bot.sendMessage(chatId, 'Пожалуйста, введите свой номер телефона:', {
        reply_markup: {
            keyboard: [[{ text: 'Отправить номер телефона', request_contact: true }]],
            one_time_keyboard: true,
        },
    });

    // Обработка введенного номера телефона
    bot.on('contact', (contactMsg) => {
        const phoneNumber = contactMsg.contact.phone_number;

        // Сохранение заказа в файл
        fs.appendFile(
            ordersFilePath,
            `OPEN: ${orderId}: ${userId}: ${orderText}: ${phoneNumber}\n`,
            (err) => {
                if (err) {
                    console.error(err);
                    bot.sendMessage(chatId, 'Произошла ошибка при сохранении заказа.');
                } else {
                    bot.sendMessage(chatId, 'Заказ сохранен. ID заказа: ' + orderId);
                    bot.sendMessage(
                        chatId,
                        'Спасибо за заказ! Пожалуйста, оставьте обратную связь по заказу:'
                    );
                }
            }
        );
    });
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
                bot.sendMessage(chatId, 'Заказ с указанным ID не найден или уже закрыт.');
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

// Запуск бота
bot.on('polling_error', (error) => {
    console.error(error);
});