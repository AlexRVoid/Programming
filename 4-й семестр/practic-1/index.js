'use strict';

var originalStrings = `Смерть – это не только конец пути, но и начало чего-то нового. 
Это последний порог, за которым окьлот начинается новый путь, на котором кто-то поднимется ещё выше, а кто-то спустится вниз.`;

var arrayOfStrings = splitString(originalStrings, ' ')

var line = 0;
function splitString(stringToSplit, separator) {
    var arrayOfStrings = stringToSplit.split(separator);
    console.log('Оригинальная строка: "' + stringToSplit + '"');
    console.log('Разделитель: "' + separator + '"');
    console.log('Массив содержит ' + arrayOfStrings.length + ' элементов: ' + arrayOfStrings.join(' / '));
    return arrayOfStrings;
}

for (var i = 0; i < arrayOfStrings.length - 1; i++){
    for (var k = 0; k <= i ; k++){
        var word = arrayOfStrings[i];
        for (var p = 0; p < word.length; p++) if (word[p] == "\n") {
            line++;
        }
    }
    for (var j = i + 1; j < arrayOfStrings.length; j++){
        var  revWord = arrayOfStrings[j].split('').reverse().join('');
        if(arrayOfStrings[i] === revWord){
            console.log('Найденно пара с перевернутым словам. На сторке ' + line + ' это слово встречается впервые.' + '\nСлова "' + arrayOfStrings[i] + '" и "' + arrayOfStrings[j] + '".');
        }
    }
}

