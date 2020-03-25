#!/bin/bash

# set -e # Halt on any error.
# set -x # Print commands.
# TEST_DIRS="/home/lucaspossatti/projects/GameOfLife/tests /home/lucaspossatti/projects/GameOfLife/secret_tests"
TEST_DIRS="/home/sarcinellirenan/NetBeansProjects/Testes/"
DEST_TESTS_DIR="$PWD/__all_tests"
SUMMARY_PATH="$DEST_TESTS_DIR/summary.txt"
TEMPLATE_FOLDER="/home/sarcinellirenan/NetBeansProjects/Gabarito"
REDIRECT_OUTPUT=true

info() {
	echo "\033[48;2;150;150;255mINFO:\033[0m $@"
}
warn () {
	echo "\033[48;2;200;200;10mWARN:\033[0m $@"
}
error () {
	echo "\033[48;2;200;10;10mERROR:\033[0m $@"
}
result () {
	echo "\033[48;2;128;0;128mRESULT:\033[0m $@"
	echo "$@" >> "$SUMMARY_PATH"
}

MAKEFILE_PATH="$PWD"

# Parse arguments.
while [ "$#" -gt "0" ]; do
	case "$1" in
		-m|--makefile)
			MAKEFILE_PATH="$2"
			shift; shift
			;;
		-b|--bin)
			BIN_PATH="$2"
			shift; shift
			;;
		-n|-o|--dont-redirect-output)
			REDIRECT_OUTPUT=false
			shift
			;;
		-*)
			error "Unknown option '$1'"
			exit 1
			;;
		*)
			error "Expected no positional arguments."
			exit 1
			;;
	esac
done

# Make sure we have a Makefile.
if [ ! -f "$MAKEFILE_PATH/Makefile" ]; then
	error "The makefile directory doesn't have a Makefile"
	exit 1
fi

CUR_DIR=$PWD
cd $MAKEFILE_PATH
# Make the project.
info "Making..."
make all > /dev/null 2> /dev/null
MAKE_ERROR_CODE="$?"
if [ "$MAKE_ERROR_CODE" -eq "0" ]; then
	info "Make's error code: $MAKE_ERROR_CODE"
else
	error "Make's error code: $MAKE_ERROR_CODE"
	exit 1
fi
cd $CUR_DIR

# Find the binary file.
if [ -z "$BIN_PATH" ]; then
	BIN_PATH=$(find "$MAKEFILE_PATH/dist/Release" -type f -perm -u=x)
	# BIN_PATH=$(find "$PWD" -name 'trabalhoprog2')
	if [ -z "$BIN_PATH" ]; then
		error "Could not find binary file."
		exit 1
	fi
	BIN_NAME=$(basename "$BIN_PATH")
	if [ "$BIN_NAME" != "trabalhoprog2" ]; then
		warn "Binary name is '$BIN_NAME' instead of 'trabalhoprog2'."
	fi
fi
info "Using this binary file: $BIN_PATH"

# Copy tests.
mkdir -p "$DEST_TESTS_DIR"
rm -r "$DEST_TESTS_DIR"/* 2>/dev/null
rsync -mr --include="*/" --include="entrada.txt" --include="config.txt" --exclude="*" $TEST_DIRS $DEST_TESTS_DIR
COPY_TESTS_ERROR_CODE="$?"
if [ "$COPY_TESTS_ERROR_CODE" -ne "0" ]; then
	error "Could not copy tests (error $COPY_TESTS_ERROR_CODE)."
	exit 1
fi

# TEST_PATHS=$(find "$DEST_TESTS_DIR" -mindepth 2 -maxdepth 2 -type d)
CONFIG_PATHS=$(find "$DEST_TESTS_DIR" -name 'config.txt')

# Clear summary.
rm -rf "$SUMMARY_PATH"

# Run each test.
for CONFIG_PATH in $CONFIG_PATHS; do
	TEST_DIR_PATH=$(dirname "$CONFIG_PATH")
	TEST_NAME=$(realpath --relative-to="$DEST_TESTS_DIR" "$TEST_DIR_PATH")
	#TEST_NAME=$(basename "$TEST_DIR_PATH")	
	# info "Running test '$TEST_DIR_PATH'..."
	mkdir -p "$TEST_DIR_PATH/saida"
	if [ "$REDIRECT_OUTPUT" = "true" ]; then
		"$BIN_PATH" "$TEST_DIR_PATH/" < "$TEST_DIR_PATH/entrada.txt" > "$TEST_DIR_PATH/saida.txt"
		EXEC_ERROR_CODE="$?"
	else
		"$BIN_PATH" "$TEST_DIR_PATH"
		EXEC_ERROR_CODE="$?"
	fi
	if [ "$EXEC_ERROR_CODE" -eq "0" ]; then
		result "Test '$TEST_NAME' OK"
	else
		result "Test '$TEST_NAME' NOT OK (error $EXEC_ERROR_CODE)"
	fi
done

meld $TEMPLATE_FOLDER $DEST_TESTS_DIR
