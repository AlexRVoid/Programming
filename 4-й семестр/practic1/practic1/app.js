'use strict';

var originalStrings = `������ � ��� �� ������ ����� ����, �� � ������ ����-�� ������. 
��� ��������� �����, �� ������� ���������� ����� ����, �� ������� ���-�� ���������� ��� ����, � ���-�� ��������� ����.`;

var arrayOfStrings = splitString(originalStrings, ' ')

function splitString(stringToSplit, separator) {
    var arrayOfStrings = stringToSplit.split(separator);
    console.log('������������ ������: "' + stringToSplit + '"');
    console.log('�����������: "' + separator + '"');
    console.log('������ �������� ' + arrayOfStrings.length + ' ���������: ' + arrayOfStrings.join(' / '));
    return arrayOfStrings;
}

console.log(arrayOfStrings);

