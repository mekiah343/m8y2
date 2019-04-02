import socket

UDP_IP_ADDRESS = "169.254.120.29"
UDP_PORT_NO = 6789
Message = "Hello, Server"

clientSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

clientSock.sendto(Message, (UDP_IP_ADDRESS, UDP_PORT_NO))
