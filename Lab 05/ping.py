import subprocess

def ping(ip):
    result = subprocess.run(['ping', '-c', '1', ip], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    return result.returncode == 0

def find_active_hosts(subnet):
    active_hosts = []
    for i in range(1, 255):
        ip = f"{subnet}.{i}"
        if ping(ip):
            active_hosts.append(ip)
            print(f"{ip} is active")
        else:
            print(f"{ip} is inactive")
    return active_hosts

if __name__ == "__main__":
    subnet = "192.168.39"
    active_hosts = find_active_hosts(subnet)
    print("\nActive hosts in the subnet:")
    for host in active_hosts:
        print(host)
