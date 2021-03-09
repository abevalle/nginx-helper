command_exists() {
	command -v "$@" >/dev/null 2>&1
}

fmt_error() {
  echo ${RED}"Error: $@"${RESET} >&2
}

setup_color() {
	# Only use colors if connected to a terminal
	if [ -t 1 ]; then
		RED=$(printf '\033[31m')
		GREEN=$(printf '\033[32m')
		YELLOW=$(printf '\033[33m')
		BLUE=$(printf '\033[34m')
		BOLD=$(printf '\033[1m')
		RESET=$(printf '\033[m')
	else
		RED=""
		GREEN=""
		YELLOW=""
		BLUE=""
		BOLD=""
		RESET=""
	fi
}

if test -f /bin/nginx-utils; then
    echo "nginx-utils is installed and up to date!"
else
    echo "nginx-utils is not installed yet"
    command_exists wget || {
        fmt_error "wget is not installed. please install wget."
        exit N
    }

    echo "Downloading nginx-utils"
    wget https://github.com/abevalle/nginx-utils/raw/master/dist/nginx-utils -O /bin/nginx-utils
    chmod a+x /bin/nginx-utils
    echo ${GREEN}"Done!"${RESET}
fi
