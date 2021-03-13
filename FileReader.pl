use strict;
use warnings;
use feature qw( say );
use Data::Show;

sub readFile
{
    my @filename = @_;

    open my $fh, '<', $filename[0] or die "Can't open $filename[0], $!";

    chomp( my @fileArr = <$fh> );

    for my $line ( @fileArr ) {
        # show $line;
        say $line;
        # system($line);
    }
    return ;
}

my @filename = ("Github.pl");

readFile($filename[0]);