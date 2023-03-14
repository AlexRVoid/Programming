'use strict';
var http = require('http');
var port = process.env.PORT || 1337;

http.createServer(function (req, res) {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    splitString(originalStrings, ' ');
}).listen(port);


var originalStrings = `Смерть – это не только конец пути, но и начало чего-то нового. 
Это последний порог, за которым начинается новый путь, на котором кто-то поднимется ещё выше, а кто-то спустится вниз.`;

//var arrayStrings = splitString(originalStrings, ' ');

function splitString(stringToSplit, separator) {
    var arrayOfStrings = stringToSplit.split(separator);
    res.end('Оригинальная строка: "' + stringToSplit + '"');
    res.end('Разделитель: "' + separator + '"');
    res.end('Массив содержит ' + arrayOfStrings.length + ' элементов: ' + arrayOfStrings.join(' / '));
    return arrayOfStrings;
}