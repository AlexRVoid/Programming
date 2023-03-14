'use strict';
var http = require('http');
var port = process.env.PORT || 1337;

http.createServer(function (req, res) {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    splitString(originalStrings, ' ');
}).listen(port);


var originalStrings = `������ � ��� �� ������ ����� ����, �� � ������ ����-�� ������. 
��� ��������� �����, �� ������� ���������� ����� ����, �� ������� ���-�� ���������� ��� ����, � ���-�� ��������� ����.`;

//var arrayStrings = splitString(originalStrings, ' ');

function splitString(stringToSplit, separator) {
    var arrayOfStrings = stringToSplit.split(separator);
    res.end('������������ ������: "' + stringToSplit + '"');
    res.end('�����������: "' + separator + '"');
    res.end('������ �������� ' + arrayOfStrings.length + ' ���������: ' + arrayOfStrings.join(' / '));
    return arrayOfStrings;
}