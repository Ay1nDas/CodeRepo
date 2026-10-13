# # System Info
# 1. uname -a            # Kernel & system info
# 2. top                 # Live task & memory usage
# 3. free -h             # RAM/Swap breakdown
# 4. df -h               # Disk space usage
# 5. du -sh .            # Directory disk usage
# 6. whoami              # Active user name
# 7. uptime              # System run duration
# 8. plasmashell -v      # KDE Plasma version

# # File Operations
# 9. pwd                 # Print working directory
# 10. ls -la             # List all files with details
# 11. cd /etc            # Change directory
# 12. mkdir lab          # Create directory
# 13. mkdir -p a/b/c     # Create nested directories
# 14. touch f1.txt       # Create empty file
# 15. cp f1.txt f2.txt   # Copy file
# 16. mv f2.txt f3.txt   # Rename/move file
# 17. rm f1.txt          # Remove file
# 18. rm -rf lab/        # Force remove directory
# 19. cat /etc/os-release# Display file content
# 20. head -n 5 /etc/passwd # First 5 lines

# # Text Processing
# 21. tail -n 5 /etc/passwd # Last 5 lines
# 22. grep "root" /etc/passwd# Search pattern
# 23. find . -name "*.txt" # Find files by pattern
# 24. less /var/log/syslog # Page file viewer
# 25. wc /etc/passwd     # Line/word/byte count
# 26. sort f3.txt        # Sort lines
# 27. uniq f3.txt        # Omit duplicate lines
# 28. cut -d: -f1 /etc/passwd # Extract fields

# # Permissions & Users
# 29. chmod 755 script.sh # rwxr-xr-x permissions
# 30. chmod +x script.sh # Grant execute mode
# 31. sudo chown root f3.txt # Change file owner
# 32. sudo chgrp root f3.txt # Change file group
# 33. sudo useradd -m u1 # Create user
# 34. sudo passwd u1     # Set user password
# 35. sudo userdel -r u1 # Delete user & home

# # Processes
# 36. ps aux             # List running processes
# 37. pgrep bash         # Get process ID by name
# 38. kill 1234          # Gracefully stop PID
# 39. kill -9 1234       # Force stop PID
# 40. killall firefox    # Stop processes by name
# 41. sleep 50 &         # Run in background
# 42. fg                 # Bring job to foreground

# # Network & Packages
# 43. ip a               # Show network interfaces
# 44. ping -c 4 8.8.8.8  # Test connectivity
# 45. wget <URL>         # Download web file
# 46. curl -I <URL>      # Fetch response headers
# 47. sudo apt update    # Refresh repo index
# 48. sudo apt upgrade -y# Upgrade packages
# 49. sudo apt install git -y # Install package
# 50. tar -czf a.tar.gz f3.txt # Create gzip archive

# Bash
# #!/bin/bash
# echo "User: $(whoami) | Host: $(hostname)"
# echo "Kernel: $(uname -r) | Uptime: $(uptime -p)"
# free -h | grep Mem:


# Bash
# #!/bin/bash
# mkdir -p "$HOME/backups"
# tar -czf "$HOME/backups/bak_$(date +%s).tar.gz" "$HOME/lab" 2>/dev/null
# echo "Backup created in $HOME/backups"



# Bash
#!/bin/bash
read -p "Path: " P
[ -e "$P" ] && echo "Exists" || echo "Missing"
[ -r "$P" ] && echo "Readable"
[ -w "$P" ] && echo "Writable"
[ -x "$P" ] && echo "Executable"

