#! usr/bin/env perl
package EPL;
require Switch;
use strict;
use warnings;

# 1)   $var = "foo" unless defined $var;      # set default after the fact
# 2)   $var = defined $var? $var : {...};     # ternary operation
# 3)   {...} if !(defined $var);              # another way to write 1)
# 4)   $var = $var || "foo";                  # set to $var unless it's falsy, in which case set to 'foo'
# 5)   $var ||= "foo";                        # retain value of $var unless it's falsy, in which case set to 'foo' (same as previous line)
# 6)   $var = $var // "foo";                  # set to $var unless it's undefined, in which case set to 'foo'
# 7)   $var //= "foo";

# BEGIN { require Module; Module->import( LIST ); }

print("Hello World!\n");

# Combinations
# Create a function that takes a variable number of arguments,
# each argument representing the number of items in a group.The function should return the number of permutations(combinations)
# of choices you would have if you selected one item from each group.

# Examples
# combinations([ 2, 3 ]) ➞ 6
# combinations([ 3, 7, 4 ]) ➞ 84
# combinations([ 2, 3, 4, 5 ]) ➞ 120

sub combination {
    my $comResult   = 1;
    my @combinArray = ( 3, 7, 4 );

    for ( my $comI = 0 ; $comI < @combinArray ; $comI = $comI + 1 ) {
        if ( $combinArray[$comI] != 0 ) {
            $comResult *= $combinArray[$comI];
        }
    }

    print( "Combination Result ", $comResult, "\n" );
}
combination();

# This robot roams around a 2D grid. It starts at (0, 0) facing North. After each time it moves, the robot rotates
# 90 degrees clockwise. Given the amount the robot has moved each time, you have to calculate the robot's final position.

# To illustrate, if the robot is given the movements 20, 30, 10, 40 then it will move:

# 20 steps North, now at (0, 20)
# 30 steps East, now at (30, 20)
# 10 steps South. now at (30, 10)
# 40 steps West, now at (-10, 10)
# ...and will end up at coordinates (-10, 10).

sub trackRobot {

    # @robotScalar = scalar(@_);

    # default value if uninitialized
    $_ //= 0;

    $_[0] //= 0;
    $_[1] //= 0;
    $_[2] //= 0;
    $_[3] //= 0;

    my $l = $_[0] + ( $_[2] * -1 );
    my $r = $_[1] + ( $_[3] * -1 );

    my @robotResult = ( $l, $r );

    # print( $l, "\n", $r, "\n" );

    print( "Robot Tracker ", $robotResult[0], ", ", $robotResult[1] );

}

trackRobot( -10, 20, 10, );

# The Fiscal Code
# Each person in Italy has an unique identifying ID code issued by the national tax office after the birth registration:
# the Fiscal Code (Codice Fiscale). Check the Resources tab for more info on this.

# Given an object containing the personal data of a person (name, surname, gender and date of birth) return the 11 code
# characters as a string following these steps:

# Generate 3 capital letters from the surname, if it has:
# At least 3 consonants then the first three consonants are used. (Newman -> NWM).
# Less than 3 consonants then vowels will replace missing characters in the same order they appear
# (Fox -> FXO | Hope -> HPO).
# Less than three letters then "X" will take the third slot after the consonant and the vowel (Yu -> YUX).

# Generate 3 capital letters from the name, if it has:
# Exactly 3 consonants then consonants are used in the order they appear (Matt -> MTT).
# More than 3 consonants then first, third and fourth consonant are used (Samantha -> SNT | Thomas -> TMS).
# Less than 3 consonants then vowels will replace missing characters in the same order they appear
# (Bob -> BBO | Paula -> PLA).
# Less than three letters then "X" will take the the third slot after the consonant and the vowel (Al -> LAX).
# Generate 2 numbers, 1 letter and 2 numbers from date of birth and gender:

# Take the last two digits of the year of birth (1985 -> 85).
# Generate a letter corresponding to the month of birth (January -> A | December -> T) using the table for conversion
# included in the code.
# For males take the day of birth adding one zero at the start if is less than 10 (any 9th day -> 09 | any 20th day -> 20).
# For females take the day of birth and sum 40 to it (any 9th day -> 49 | any 20th day -> 60).

# fiscalCode({
#     name : "Matt",
#     surname : "Edabit",
#     gender : "M",
#     dob : "1/1/1900"
# }) ➞ "DBTMTT00A01"

#     fiscalCode({
#         name : "Helen",
#         surname : "Yu",
#         gender : "F",
#         dob : "1/12/1950"
#     }) ➞ "YUXHLN50T41"

#     fiscalCode({
#         name : "Mickey",
#         surname : "Mouse",
#         gender : "M",
#         dob : "16/1/1928"
#     }) ➞ "MSOMKY28A16"

sub fiscalCode {
    use Switch;

    $_ = my %fiscalCode;

    my $c, my $fiscal_result = '';
    my @vowel_array, my @name_array, my @sur_array = ();

    my $lowercase =
      ( $c == 'a' || $c == 'e' || $c == 'i' || $c == 'o' || $c == 'u' );
    my $uppercase =
      ( $c == 'A' || $c == 'E' || $c == 'I' || $c == 'O' || $c == 'U' );

    my @string_array = split( '', $_{'surname'} );

    my @lowervowels  = ( 'a', 'e', 'i', 'o', 'u' );
    my @highervowels = ( 'A', 'E', 'I', 'O', 'U' );

    for ( my $j = 0 ; $j < scalar @string_array ; $j = $j + 1 ) {
        for ( my $k = 0 ; $k <= 5 ; $k = $k + 1 ) {
            if (   @string_array[$j] == @lowervowels[$k]
                || @string_array[$j] == @highervowels[$k] )
            {
                print "true";
            }
        }
    }

    # string manipulation of surname
    for ( my $i = 0 ; $i < scalar $a ; $i = $i + 1 ) {

        #    for my $a (@string_array[$i]) {
        # $a[$i];
        if ( $string_array[$i] eq $c ) {
            @vowel_array[$i] = $string_array[$i];
        }
        else {
            @sur_array[$i] = $string_array[$i];
        }
    }
    if ( scalar @sur_array < 2 ) {
        push( @sur_array, 'X' );
    }
    elsif ( scalar @sur_array < 3 ) {
        push( @sur_array, $vowel_array[0] );
    }
    else {
        @sur_array = @sur_array[ 0 .. 2 ];

    }

    # push to result array before vowel array
    push( my @fiscal_result, @sur_array );

    @vowel_array = ();

    @string_array = split( " ", $_{'name'} );

    # string manipulation of name
    for ( my $i = 0 ; $i < scalar @string_array ; $i = $i + 1 ) {
        if ( $string_array[$i] == $c ) {
            @vowel_array[$i] = $string_array[$i];
        }
        else {
            @name_array[$i] = $string_array[$i];
        }
    }
    if ( scalar @name_array < 1 ) {
        push( @name_array, $vowel_array[0], 'X' );
    }
    elsif ( scalar @name_array <= 2 ) {
        @name_array = @name_array[ 0 ... 1 ];
        push( @name_array, $vowel_array[0] );
    }
    elsif ( scalar @name_array == 3 ) {
        @name_array = @name_array[ 0 ... 2 ];
    }
    else {
        @name_array = $name_array[0] + $name_array[3] + $name_array[4];
    }

    # string manipulation for year
    my $year = $_{'dob'}[ length( $_{'dob'} ) - 1, length( $_{'dob'} ) ];

    # string manipulation to produce letter based on month
    my $month;
    my $month_char;
    switch ($month) {
        case 1  { $month_char = 'A' }
        case 2  { $month_char = 'B' }
        case 3  { $month_char = 'C' }
        case 4  { $month_char = 'D' }
        case 5  { $month_char = 'E' }
        case 6  { $month_char = 'F' }
        case 7  { $month_char = 'G' }
        case 8  { $month_char = 'H' }
        case 10 { $month_char = 'I' }
        case 11 { $month_char = 'J' }
        case 12 { $month_char = 'K' }
    }

    # string manipulation to produce day based on gender
    my $day = ( split( "/", $_{'dob'} ) )[0];

    my $string_day;
    if ( $_{'gender'} == 'M' ) {
        if ( my $day < 10 ) {
            $string_day = '0' + $day;
        }
    }
    else {
        $string_day = $day + 40;
    }

    # final result combining all value
    # perl should automatically do type conversion
    my $sur_array  = join( '', @sur_array );
    my $name_array = join( '', @name_array );
    $fiscal_result =
      $sur_array + $name_array + $year + $month_char + $string_day;

}

our %fiscal_code =
  ( "name", "Mickey", "surname", "Mouse", "gender", "M", "dob", "16/1/1928" );

fiscalCode( \%fiscal_code );

