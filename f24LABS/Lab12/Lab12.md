## Lab 12

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu

## Part 1 - Linux Network Command Cheat Sheet

- `hostname` 
``` 
displays the system's host name (DNS name) and allows you to change it. 
Includes flags like -i/I to get all IP 
addresses and -b to set/change the hostname. 
```
    - Resource on `hostname`: https://www.geeksforgeeks.org/hostname-command-in-linux-with-examples/

- `ifconfig`
```
ifconfig is part of the net-tools linux toolpack for network interface configuration. 
Man linux entry says it prints the status of currently active interfaces when called without arguments.
includes flags to specify the interface to change, as well as flags to activate/deactivate a specific
interface, and ways to change networks mask and broadcast mask for a specific interface. 
```
    - Resource on `ifconfig`: https://phoenixnap.com/kb/linux-ifconfig

- `ip a`
```
command for network configuration, allows interaction with network interfaces, routing tables, etc. 
replacement for ifconfig. has to be given a networking component to work with, then can perform commands
like "address" to display ip addresses associated with the component, "route", "add", "del", etc
```
    - Resource on `ip`: https://www.geeksforgeeks.org/ip-command-in-linux-with-examples/

- `route`
```
displays the IP routing table and can be used to modify it. running w/o flags will display the routing
table entries. flags include del/add to delete or add, target to specify destination, gw to route via
a gateway, etc etc etc
```
    - Resource on `route`: https://www.computerhope.com/unix/route.htm

- `iptables -L`
```
iptables allows configuration of the linux firewall. it lets the user define chained rules for incoming
and outgoing network traffic. iptables is made up of tables with rule chains. -L flag lists all the rules 
in a chain. 
```
    - Resource on `iptables`: https://phoenixnap.com/kb/iptables-linux

- `curl <IP_or_hostname>`
```
curl is a command to transfer data across severs. can transfer data using HTTP, HTTPS, FTP, etc. most 
simple use is just to fetch a web page, ex "curl https://wttr.in". allows for resume of transfers, user
auth, bandwidth limitation, etc
```
    - Resource on `curl`: https://linuxize.com/post/curl-command-examples/

- `ping <IP_or_hostname>`
```
ping is a tool to test network connectivity by sending out an echo to request packets from the target host.
it waits until it gets a reply and iforms the user of the round trip time and packet loss. has options like 
-c to specify number of ping requests sent, -i for wait interval, -I to set source, etc.
```
    - Resource on `ping`: https://phoenixnap.com/kb/linux-ping-command-examples

- `nslookup <IP_or_hostname>`
```
nslookup is name server lookup and lets the user find an ip address or DNS record for a specified domain name. 
ex. if you want the ip address of a specific website. also works other way arround: can find domain name with
just ip address. works by entering just "nslookup" on command line, then using secondary commands in the prompt
that appears. 
```
    - Resource on `nslookup`: https://nordvpn.com/blog/nslookup-command/

- `traceroute <IP_or_hostname>`
```
tracks the path that a packet takes from the source to the destination (ex user's device to a website) over
an IP newtork. includes info about how many routers the packet had to go through. options include -4 and -6
to indicate ipv4 or ipv6, -m to set max hops, -p for dest port, etc. 
```
    - Resource on `traceroute`: https://www.geeksforgeeks.org/traceroute-command-in-linux-with-examples/

- `nmap -p <IP_or_hostname>` 
```
nmap is network mapper which is network tool. allows adnins to see hosts and services on systems. can use server
names, ipv4, or ipv6. includes various flags that can be used to specify which info to look for.
```
    - Resource on `nmap`: https://phoenixnap.com/kb/nmap-commands

- `tcpdump -i <networkinterface> -n host <IP_or_hostname>`
```
tcpdump allows system admins to analyze TCP/IP packets moving through the system/over the network. can 
also be used as a security tool. has flags like -c to exit after rercieving a certain number of packets, 
-i to specify where to capture packeets from, etc.
```
    - Resource on `tcpdump`: https://www.geeksforgeeks.org/tcpdump-command-in-linux-with-examples/

## Part 2 - Network Info

### Network Info for <Your OS Here>

1. Hostname of the device:
2. MAC address of the NIC connected to the network:
3. IPv4 address:
4. Subnet mask:
5. Gateway address:
6. Does the device use DHCP to receive a network address? (y/n):
7. DNS server address:
8. Public IPv4 address:

### Network Info for AWS Instance

1. Hostname of the device:
2. MAC address of the NIC connected to the network:
3. IPv4 address:
4. Subnet mask:
5. Gateway address:
6. Does the device use DHCP to receive a network address? (y/n):
7. DNS server address:
8. Public IPv4 address:

## Part 3 - Subnet Translation

Translate the below CIDR blocks to their IP ranges:
1. `130.108.0.0/16`
2. `34.117.59.81/32`
3. `10.25.121.90/8`

Translate the below IP ranges to their CIDR notation subnets:
1. `172.18.5.0 - 172.18.5.255`
2. `5.9.243.187 - 5.9.243.187`
3. `192.168.0.0 - 192.168.1.255`

## Part 4 - Security

Screenshot of your changed Inbound Security Group rules.  
![Inbound Rules for Lab 12](relative/path/to/image)

> Why should HTTP allow any IP, while SSH has restrictions?

> Describe how you validated or can validate if your rules are working with the restrictions given.

## Part 5 - It's Alive!  Maybe...

1. For the given server IP, describe purpose and what types of requests it does / doesn't respond to:
    - `8.8.8.8`
        - Purpose:
        - Responds to:
        - Does not respond to: 
    - `5.9.243.187` -> `wttr.in` -> `https://wttr.in`
        - Purpose:
        - Responds to:
        - Does not respond to: 
    - Your AWS instance public IP
        - Purpose:
        - Responds to:
        - Does not respond to: 
    - `34.117.59.81` -> `ipinfo.io` -> `https://ipinfo.io`
        - Purpose:
        - Responds to:
        - Does not respond to: 
2. Does `ping` tell you if a server is "working"?
3. What protocol does `ping` use?  What does this mean about the server's firewalls?
4. Why won't `ping` work if you specify `https://` before the domain name?
5. Does an IP lookup always result in finding the correct domain name / URL to access the resource, and vice versa?
6. What happens at when an `http` request is made to a server with `https` enabled?

Citations:
- <add bullets of citations / links used here>

## Extra Credit - Tattle Tale

### IPv4 Source Report

| Rank  | IPv4 Address | # of Attempts |
| ----- | ------------ | ------------- |
| 1     |              |     |
| 2     |              |     |
| 3     |              |     |
| 4     |              |     |
| 5     |              |     |

Commands to parse `csv` for report:

### Username Used Report

| Rank  | Username     | # of Attempts |
| ----- | ------------ | ------------- |
| 1     |              |     |
| 2     |              |     |
| 3     |              |     |
| 4     |              |     |
| 5     |              |     |

Commands to parse `csv` for report:
