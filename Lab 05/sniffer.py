from scapy.all import sniff
import sys

# Replace this with the IP address of google.com from your ping result
GOOGLE_IP = "142.250.195.14"

def packet_callback(packet):
    print("Packet captured from google.com:", packet.summary())
    sys.exit(0)  # Exit after capturing one packet

try:
    print(f"Sniffing packets from {GOOGLE_IP}...")
    sniff(filter=f"host {GOOGLE_IP}", prn=packet_callback, count=1)
except Exception as e:
    print(f"Error: {e}")
