def clear_screen():				# Function to clear the screen
    if os.name == "posix":		# Unix/Linux/MacOS/BSD/etc
        os.system('clear')		# Clear the Screen
    elif os.name in ("nt", "dos", "ce"):	# DOS/Windows
        os.system('CLS')					# Clear the Screen