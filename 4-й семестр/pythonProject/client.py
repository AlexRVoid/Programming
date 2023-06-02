import socket


def client() -> None:
    """
    Эхо
    """
    HOST = '217.71.129.139'  # Внешний IP PORT сервера, в нашем случае гипервизора
    # который перенаправляет запрос на нужный порт нашего сервера
    PORT = 5561

    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # Создаем instance класса
    client_socket.connect((HOST, PORT))  # Подключаемся к серверу

    message = input(" >> ")  # Вводим данные

    while message.lower().strip() != 'bye':
        client_socket.send(message.encode())  # Отправялем данные

        data = client_socket.recv(1024).decode()  # Получаем ответ
        print('Received from server: ' + data)

        message = input(" >> ")  # Повтор ввода
    client_socket.close()  # закрываем соединение


if __name__ == '__main__':
    client()
