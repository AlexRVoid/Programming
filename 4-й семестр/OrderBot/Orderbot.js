const TelegramBot = require('node-telegram-bot-api');
const fs = require('fs');

// Токен вашего бота, полученный от BotFather
const token = '6239041673:AAGfUhZTyYUupwFRJHUKLaKL-VjsyPqH9SQ';

// Создание экземпляра бота
const bot = new TelegramBot(token, { polling: true });

// Обработчик команды /start
bot.onText(/\/start/, (msg) => {
    const chatId = msg.chat.id;
    bot.sendMessage(chatId, 'Добро пожаловать! Чтобы сделать заказ, введите /order <текст заказа>');
});

// Обработчик команды /order
bot.onText(/\/order (.+)/, (msg, match) => {
    const chatId = msg.chat.id;
    const orderText = match[1];

    // Сохранение заказа в файл
    fs.appendFile('orders.txt', `${chatId}: ${orderText}\n`, (err) => {
        if (err) {
            console.error(err);
            bot.sendMessage(chatId, 'Произошла ошибка при сохранении заказа.');
        } else {
            bot.sendMessage(chatId, 'Заказ сохранен.');
        }
    });
});

// Запуск бота
bot.on('polling_error', (error) => {
    console.error(error);
});
