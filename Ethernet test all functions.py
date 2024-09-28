
import socket
import threading

# Function to listen for TCP messages
def listen_for_tcp(port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('0.0.0.0', port))
    server_socket.listen(5)
    print(f"Listening for TCP connections on 0.0.0.0:{port}...")
    
    while True:
        client_socket, addr = server_socket.accept()
        print(f"TCP connection established with {addr}")
        while True:
            try:
                message = client_socket.recv(1024).decode()
                if not message:
                    break
                print(f"Received TCP message: {message}")
            except ConnectionResetError:
                break
        client_socket.close()

# Function to listen for UDP messages
def listen_for_udp(port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('0.0.0.0', port))
    print(f"Listening for UDP messages on 0.0.0.0:{port}...")
    
    while True:
        message, addr = server_socket.recvfrom(1024)
        print(f"Received UDP message: {message.decode()} from {addr}")

# Function to send TCP messages
def send_tcp_message(ip, port, message):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect((ip, port))
        client_socket.sendall(message.encode())
        print(f"TCP message sent to {ip}:{port}: {message}")
    except Exception as e:
        print(f"Failed to send TCP message: {e}")
    finally:
        client_socket.close()

# Function to send UDP messages
def send_udp_message(ip, port, message):
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        client_socket.sendto(message.encode(), (ip, port))
        print(f"UDP message sent to {ip}:{port}: {message}")
    except Exception as e:
        print(f"Failed to send UDP message: {e}")
    finally:
        client_socket.close()

# Main function
def main():
    tcp_port = 5000  # Specify your TCP listening port
    udp_port = 5000  # Specify your UDP listening port

    # Start listener threads
    threading.Thread(target=listen_for_tcp, args=(tcp_port,), daemon=True).start()
    threading.Thread(target=listen_for_udp, args=(udp_port,), daemon=True).start()
    ip = '169.254.253.158'
    while True:
        choice = input("Choose option:\n1. Send TCP message\n2. Send UDP message\n3. Exit\n> ")
        
        if choice == '1':
            message = input("Enter TCP message to send: ")
            send_tcp_message(ip, tcp_port, message)
        elif choice == '2':
            message = input("Enter UDP message to send: ")
            send_udp_message(ip, udp_port, message)
        elif choice == '3':
            break
        else:
            print("Invalid choice. Please select 1, 2, or 3.")

if __name__ == "__main__":
    main()
