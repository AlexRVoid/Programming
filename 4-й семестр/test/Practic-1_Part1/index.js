'use strict';

var originalStrings = `Смерть – это не только конец пути, но и начало чего-то нового. 
Это последний порог, за которым окьлот начинается новый гороп путь, на котором: кто-то поднимется ещё выше, а кто-то спустится вниз.`;// Оригинальная строка внутра которой выполняется поиск
var lineWithoutPunctuation = originalStrings.replace(/,/g, "").replace(/\./g, "")
    .replace(/:/g, "").replace(/;/g, "").replace(/"/g, "")
    .replace(/'/g, "").replace(/\(/g, "").replace(/\)/g, "");//Удаление лишних знаков из строк
var arrayOfStrings = splitString(lineWithoutPunctuation, ' ')// Вызов функ разбиения и передача ей строки оригинала и символа разбиения

var line = 0;
function splitString(stringToSplit, separator) {// Разбиение строки на слова и запись их в массив
    var arrayOfStrings = stringToSplit.split(separator);
    console.log('Оригинальная строка: "' + stringToSplit + '"');
    console.log('Разделитель: "' + separator + '"');
    console.log('Массив содержит ' + arrayOfStrings.length + ' элементов: ' + arrayOfStrings.join(' / '));// вывод преобразованных строк
    return arrayOfStrings;// Возврат преобразованной строки
}

for (var i = 0; i < arrayOfStrings.length - 1; i++){// Цикл поиска зеркальных слов по средствам сравнения инвертированных слов в строке с обычной строкой

        var word = arrayOfStrings[i];
        for (var p = 0; p < word.length; p++) if (word[p] == "\n") {// подсчёт строк
            line++;
        }

    for (var j = i + 1; j < arrayOfStrings.length; j++){// сравнение инверсированных и обычных элементов строки
        var  revWord = arrayOfStrings[j].split('').reverse().join('');
        if(arrayOfStrings[i] === revWord){
            console.log('Найденно пара с перевернутым словам. На сторке ' + line + ' это слово встречается впервые.' + '\nСлова "' + arrayOfStrings[i] + '" и "' + arrayOfStrings[j] + '".');
        }
    }
}

