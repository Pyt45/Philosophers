#!/usr/bin/perl

use strict;
use warnings;
use feature qw( say );
# use Data::Dumper;
# use Data::Show;
print "hello\n";
# use Data::Printer;
# use LWP::UserAgent;
# use Time::Piece;

# sub modify
# {
# 	my %hash = @_;

# 	$hash{new_value} = 2;

# 	print Dumper("Within the subroutine");
# 	print Dumper(\%hash);

# 	return ;
# }

# my %example_hash = (
# 	old_value => 1,
# );

# modify(%example_hash);

# print Dumper("After exitin the subroutine");
# print Dumper(\%example_hash);
# my $num = 1;
# my $name = "ayoub";
# my @char = ('a', 'b', 'c');
# my %map = (a => 12, b => 15, c => 19);

# use constant {
# 	PI => '3.1415926'
# };

# my $array_refrence = \@array;
# my $arr = [1, 2, 3];

# print Dumper(\@array);
# print Dumper(\$array_refrence);
# print Dumper(\$arr);
# print "Hello $name!\n";
# print "$char[1]\n";
# printf("char[0] = %s\n", $char[0]);
# print "map[b] is $map{b}\n";

# print "\n==================\n\n";
# print "I Like PI\n";
# print "PI = " . PI . "\n";

# say 0 ? 'true' : 'false';
# say 5 ? 'true' : 'false';

# print "\n==================\n\n";
# my $date = localtime->strftime('%m/%d/%Y');
# print "$date\n";

# Control Statment

# my @num = 1..5;

# for (my $i=0; $i <= $#num; $i++)
# {
# 	if ($num[$i] % 3 == 0)
# 	{
# 		say $num[$i];
# 	}
# }

# printf("===========================\n");

# foreach my $j (@num) {
# 	say $j;
# }

# my $n = 0;

# do {
# 	say "Hi";
# 	$n++;
# } until($n > 5);

# Subroutines

# sub sum {
# 	my $ret = 1;

# 	for my $val (@_) {
# 		$ret += $val;
# 	}
# 	return $ret;
# }

# sub fact {

# }
# my $ua = LWP::UserAgent->new;
# p $ua;

# say sum 1..5;

# my $data = { foo => 'bar' };
# print Dumper $data;

# my @arr = 1..10;

# my %hash = ( foo => 1, bar => { baz => 10, qux => 20 } );

# my $href = \%hash;

# show @arr;
# show %hash;
# show $href;

################################ File I/O (Reading and Writing files) #################################
# my $filename = "file";

# open my $filehandle, '<', $filename or die "Can't open $filename, $!";

#while (chomp(my $line = <$filehandle>)) {
# 	say $line;
#}

# chomp( my @fileArr = <$filehandle> );

# for my $val ( @fileArr ) {
# 	print "$val \n";
# }