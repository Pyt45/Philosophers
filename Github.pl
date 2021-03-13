use strict;
use warnings;
use feature qw( say );
use Data::Show;
use Git::Repository;

my $url = "https://github.com/Pyt45/docker-compose.git";
my $dir = "docker-compose";
Git::Repository->run( clone => $url, $dir );
my $r = Git::Repository->new( work_tree => $dir );