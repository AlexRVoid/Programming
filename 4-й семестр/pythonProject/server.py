import socket


def server() -> None:
    """
    Эхо
    """
    HOST = '172.17.9.192'  # Слушаем не localhost, а внутренний адрес VDS
    # Узнать его можно либо на сайте хостинга, либо через команду ip a
    PORT = 6666  # Инициализируем порт, не ниже 1024, т.к. ниже - зарезервированно

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  # instance класса socket
    server_socket.bind((HOST, PORT))  # биндит hostname и необходимый порт. Принимает кортеж
    server_socket.listen(2)  # Кол-во клиентов, которых сервер одновременно слушает

    conn, address = server_socket.accept()  # Принимаем новое соединение
    print("Connection from: " + str(address))

    while True:
        # Получаем поток данных. Не принимаем данные больше 1 Кб
        data = conn.recv(1024).decode()

        if not data:
            # Если данные не получены - обрыв
            break
        print("From connected user: " + str(data))

        conn.send(data.encode())  # Отправляем клиенту его же данные
    conn.close()  # Закрываем соединение


if __name__ == '__main__':
    server()
