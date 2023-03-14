'use strict';

var originalStrings = `Смерть – это не только конец пути, но и начало чего-то нового. 
Это последний порог, за которым начинается новый путь, на котором кто-то поднимется ещё выше, а кто-то спустится вниз.`;

var arrayOfStrings = splitString(originalStrings, ' ')

function splitString(stringToSplit, separator) {
    var arrayOfStrings = stringToSplit.split(separator);
    console.log('Оригинальная строка: "' + stringToSplit + '"');
    console.log('Разделитель: "' + separator + '"');
    console.log('Массив содержит ' + arrayOfStrings.length + ' элементов: ' + arrayOfStrings.join(' / '));
    return arrayOfStrings;
}

console.log(arrayOfStrings);

