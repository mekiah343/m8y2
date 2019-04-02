import socket

UDP_IP_ADDRESS = "169.254.120.29"
UDP_PORT_NO = 6789

# declare our serverSocket upon which
# we will be listening for UDP messages
serverSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# One difference is that we will have to bind our declared IP address
# and port number to our newly declared serverSock
serverSock.bind((UDP_IP_ADDRESS, UDP_PORT_NO))

print "started"

while True:
    data, addr = serverSock.recvfrom(1024)
    print "Message: ", data
