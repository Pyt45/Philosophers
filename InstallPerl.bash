#!/usr/bin/env bash


# which -s brew
# if [[ $? != 0 ]] ; then
# 	echo "Brew not installed, installling..."
# 	# Install brew
# 	rm -rf $HOME/.brew
# 	git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew
# 	echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc
# 	source $HOME/.zshrc
# fi
# echo "Updating brew..."
# brew update > /dev/null
# # Installing perl
# which -s perl
# if [[ $? != 0 ]]; then
# 	echo "Perl not installed, installing..."
# 	brew install perl
# 	echo "Perl installed"
# fi
# which -s cpan
# if [[ $? != 0 ]]; then
# 	echo "Cpan not installed, installing..."
# 	brew install cpan
# 	echo "Cpan installed"
# fi

# echo -n "yes" | cpan App::cpanminus
# cpanm Git::Repository

# file="file";
# while IFS= read -r line || [ -n "$line" ]; do
# 	eval $line;
# done <file

FILENAME="/etc/passwd"
while IFS=: read -r username password userid groupid comment homedir cmdshell
do
	echo "$username, $userid, $comment, $homedir"
done <$FILENAME

# perl MyTools.pl