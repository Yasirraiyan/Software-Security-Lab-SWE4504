import socket
import struct

# Create a raw socket to capture packets
sniffer = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_IP)

# Bind to local machine (Change IP if needed)
HOST = "192.168.1.100"  # তোমার লোকাল IP দিয়ে আপডেট করো
sniffer.bind((HOST, 0))

# Include IP headers
sniffer.setsockopt(socket.IPPROTO_IP, socket.IP_HDRINCL, 1)

# Windows-এ Promiscuous mode চালু করতে হবে
try:
    sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_ON)
except AttributeError:
    pass  # Ignore if not on Windows

# Function to decode IP header
def parse_ip_header(packet):
    ip_header = packet[:20]  # প্রথম 20 বাইট হলো IP হেডার
    iph = struct.unpack("!BBHHHBBH4s4s", ip_header)

    version_ihl = iph[0]
    version = version_ihl >> 4  # Extract IP version
    ihl = version_ihl & 0xF  # Extract header length
    ttl = iph[5]
    protocol = iph[6]
    src_address = socket.inet_ntoa(iph[8])  # Convert source IP
    dest_address = socket.inet_ntoa(iph[9])  # Convert destination IP

    print(f"Version: {version}, Header Length: {ihl * 4}, TTL: {ttl}")
    print(f"Protocol: {protocol}, Source: {src_address}, Destination: {dest_address}")

print("Listening for one packet...")

# Capture a packet
packet, addr = sniffer.recvfrom(65565)
parse_ip_header(packet)

# Windows-এ Promiscuous mode বন্ধ করতে হবে
try:
    sniffer.ioctl(socket.SIO_RCVALL, socket.RCVALL_OFF)
except AttributeError:
    pass  # Ignore if not on Windows
HOST = "10.220.78.217"  # তোমার লোকাল IP
from scapy.all import *

# প্যাকেট স্নিফ করার জন্য ফাংশন
def packet_callback(packet):
    print(packet.show())

# প্যাকেট ক্যাপচার করা
sniff(prn=packet_callback, count=1)
