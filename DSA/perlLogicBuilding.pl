package DSA;
use strict;
use warnings;

sub multiplicationTable {
    my $i     = 1;
    my $j     = 1;
    my $iter  = ( 1 .. 10 );
    my $times = 9;

    # for ($iter) {
    #     print( $times * $i, "\n" );
    #     $i++;
    # }

    # print($times * $i, "\n");

    for ( $i = 1 ; $i < 10 ; $i++ ) {
        print( $i * $j, " " );
        for ( $i = 1 ; $i <= 10 ; $i++ ) {
            print( $times * $i, "\n" );
        }
    }
}

our $times = 9;

multiplicationTable( \$times );

