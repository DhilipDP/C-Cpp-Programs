
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define BigInt StrInt
using namespace std;

struct QuoRem;


string itostring( int i )
{
    ostringstream oss;
    oss << i;
    return oss.str();
}

class StrInt
{
public:
    StrInt( const string& s = "0" ) : snum(s)
    { normalize(); delLeadZeros(); }
    
    StrInt( int s ) : snum( itostring(s) ) { normalize(); }

    
private:
    string snum;
    char sign;

    void normalize()
    {
        // trim off all leading and trailing whitespaces ...
        trim( snum ); 
        
        if( snum[0] == '-' || snum[0] == '+' )
            { sign = snum[0]; snum.erase(0, 1); }
        else sign = '+';

        int len = snum.size();
        for( int i = 0; i < len; ++i ) 
            if( snum[i] < '0' || '9' < snum[i] )
            /* if not a valid integer ... set to "0" */
                { snum = "0"; break; }
    }
    // erase leading zeros ... but NOT last zero
    void delLeadZeros()
    {
        int i = 0, j = snum.size() -1;
        while( i < j && snum[i] == '0' ) ++i;
        snum.erase( 0, i );
        if( snum == "0" ) sign = '+';
    }
    
    // trim leading and trailing whitespaces from 's' ... and return by 'ref.'
    static void trim( string& s, const string t = " \t" ) // default whitespace: "\t "
    {
        size_t p1 = s.find_first_not_of( t ); // get index of 'first char' ...
        if( string::npos != p1  ) // ok ... not all ws ... nor empty ... so can safely
        {
            s.erase( 0, p1 );
            size_t p2 = s.find_last_not_of( t ); // get index of 'last char' ...
            s.erase( p2+1 );
        }
        else // ... all whitespaces or empty
            s.clear();
    }

    friend ostream& operator << ( ostream& os, const StrInt& s )
    { return os << "("<< (s.sign == '-' ? "-" : "") << s.snum << ")"; }
    
    // comapres the absolute values ...
    
	 friend bool operator >= ( const BigInt& a, const BigInt& b )
    {
        int len1 = a.snum.size(), len2 = b.snum.size();
        if( len1 > len2 ) return true;
        if( len1 == len2 ) return a.snum >= b.snum;
        return false;
    }
    friend bool operator > ( const BigInt& a, const BigInt& b )
    {
        int len1 = a.snum.size(), len2 = b.snum.size();
        if( len1 > len2 ) return true;
        if( len1 == len2 ) return a.snum > b.snum;
        return false;
    }
    friend bool operator == ( const BigInt& a, const BigInt& b )
    {
        if( a.snum == b.snum ) return true;
        return false;
    }
    friend bool operator != ( const BigInt& a, const BigInt& b )
    {
        if( a.snum != b.snum ) return true;
        return false;
    }
    friend bool operator <= ( const BigInt& a, const BigInt& b )
    {
        int len1 = a.snum.size(), len2 = b.snum.size();
        if( len1 < len2 ) return true;
        if( len1 == len2 ) return a.snum <= b.snum;
        return false;
    }
    friend bool operator < ( const BigInt& a, const BigInt& b )
    {
        int len1 = a.snum.size(), len2 = b.snum.size();
        if( len1 < len2 ) return true;
        if( len1 == len2 ) return a.snum < b.snum;
        return false;
    }

    friend StrInt operator - ( const StrInt& a )
    {
        StrInt b = a;
        if( b.snum == "0" ) { b.sign = '+'; return b; }
        // else ...
        b.sign = ( a.sign == '+' ? '-' : '+' );
        return b;
    }

    friend char sumof( const StrInt& a, int len1, const StrInt& b, int len2, int& carry )
    {
        int sum = a.snum[len1]-'0' + b.snum[len2]-'0' + carry;
        if( sum > 9 ) { sum -= 10; carry = 1; }
        else carry = 0;
        return char( '0' + sum );
    }
    friend char sumof( const StrInt& s, int len, int& carry )
    {
        int sum = s.snum[len]-'0' + carry;
        if( sum > 9 ) { sum -= 10; carry = 1; }
        else carry = 0;
        return char( '0' + sum );
    }

    // uses both friend functions above ...
    friend StrInt operator + ( const StrInt& a, const StrInt& b )
    {
        int len1 = a.snum.size();
        int len2 = b.snum.size();
        int ml = (len1 > len2 ? len1 : len2);
        StrInt s;
        s.snum.resize( ml );

        if( a.sign == b.sign )
        {
            int carry = 0;
            while( len1 && len2 )
                s.snum[--ml] = sumof( a, --len1, b, --len2, carry );
            if( len1 )
            {
                while( len1 )
                    s.snum[--ml] = sumof( a, --len1, carry );
            }
            else if( len2 )
            {
                while( len2 )
                    s.snum[--ml] = sumof( b, --len2, carry );
            }

            if( carry )
                s.snum = "1" + s.snum;

            s.sign = a.sign;
            return s;
        }
        
        // if reach here ... signs are different ... //

        else if( a >= b ) // i.e. abs(a) >= abs(b) ...
        {
            if( a.sign == '+' ) return a - (-b);
            else return -((-a) - b);
        }
        else
        {
            if( b.sign == '+' ) return b - (-a);
            else return -((-b) - a);
        }
    }
    
    // abs(a) >= abs(b) ...
    friend char difof( const StrInt& a, int len1, const StrInt& b, int len2, int& carry )
    {
        int sum = a.snum[len1]-'0' - (b.snum[len2]-'0') + carry;
        if( sum < 0 ) { sum += 10; carry = -1; }
        else carry = 0;
        return char( '0' + sum );
    }
    friend char difof( const StrInt& s, int len, int& carry )
    {
        int sum = s.snum[len]-'0' + carry;
        if( sum < 0 ) { sum += 10; carry = -1; }
        else carry = 0;
        return char( '0' + sum );
    }

    // uses both friend functions above ...
    friend StrInt operator - ( const StrInt& a, const StrInt& b )
    {
        int len1 = a.snum.size();
        int len2 = b.snum.size();
        int ml = (len1 > len2 ? len1 : len2);
        StrInt s;
        s.snum.resize( ml );

        int carry = 0;
        if( a.sign == b.sign )
        {
            if( a >= b )
            {
                while( len1 && len2 )
                    s.snum[--ml] = difof( a, --len1, b, --len2, carry );
                while( len1 )
                    s.snum[--ml] = difof( a, --len1, carry );
                s.sign = a.sign;
                s.delLeadZeros();
                return s;
            }
            else
            {
                while( len2 && len1 )
                    s.snum[--ml] = difof( b, --len2, a, --len1, carry );
                while( len2 )
                    s.snum[--ml] = difof( b, --len2, carry );
                s.sign = b.sign;
                s.delLeadZeros();
                return -s;
            }
        }
        //else if( a.sign == '+' ) return a + (-b);
        else return a + (-b);
    }
    
    // a >= 0 ...
    friend char productof( int a, const StrInt& b, int len2, int& carry )
    {
        int sum = a * (b.snum[len2]-'0') + carry;
        if( sum > 9 ) { carry = sum/10; sum = sum%10; }
        else carry = 0;
        return char( '0' + sum );
    }
    friend StrInt operator * ( int a, const StrInt& b )
    {
        int len2 = b.snum.size();
        StrInt s;
        s.snum.resize( len2 );

        char signA = '+';
        if( a < 0 ) { a = -a; signA = '-'; }

        int carry = 0;

        while( len2-- )
            s.snum[len2] = productof( a, b, len2, carry );

        if( carry )
            s.snum = char( '0'+carry ) + s.snum;

        if( signA == b.sign ) s.sign = '+';
        else s.sign = '-';

        s.delLeadZeros();
        return s;
    }

    // uses both friend functions above ...
    friend StrInt operator * ( const StrInt& a, const StrInt& b )
    {
        StrInt s; // initial value is zero ...
        
        if( a >= b )
        {
            int len1 = b.snum.size();
            while( len1-- )
            {
                StrInt n = (b.snum[len1]-'0') * ( a.sign == '+' ? a : -a ) ;
                n.delLeadZeros();
                
                // shift left ... before adding ..
                n.snum += string( b.snum.size()-1-len1, '0' );
                s = s + n;
            }
        }
        else
        {
            int len1 = a.snum.size();
            while( len1-- )
            {
                StrInt n = (a.snum[len1]-'0') *  ( b.sign == '+' ? b : -b );
                n.delLeadZeros();

                // shift left ... before adding ...
                n.snum += string( a.snum.size()-1-len1, '0' );
                s = s + n;
            }
        }
        s.sign = ( a.sign == b.sign ? '+' : '-' );

        if( s.snum == "0" ) s.sign = '+';
        return s;
    }
    
    
    friend BigInt division( const BigInt& dividend, const BigInt& divisor, BigInt& remain );
    friend QuoRem operator / ( const BigInt& dividend, const BigInt& divisor );

} ;


struct QuoRem
{
	StrInt quo;
    StrInt rem;
};


BigInt division( const BigInt& dividend, const BigInt& divisor, BigInt& remain )
{
    BigInt quotient(1);

    if( divisor > dividend ) // if( abs(divisor) > abs(dividend) ) ...
    {
        quotient = BigInt();
        remain = dividend;
    }
    else if( divisor == dividend )
    {
		// quotient already initialed to 1 above ...
        /* quotient = BigInt(1); */
        remain = BigInt();
    }
    else
    {
        BigInt tmp_divisor = divisor;
        while( tmp_divisor <= dividend )
        {
            /*
                Here divisor <= dividend, therefore ...
                left shift (i.e. multiply by 2) ...  divisor and quotient
            */
            tmp_divisor = 2*tmp_divisor; // times 2 ...
            quotient = 2*quotient;
        }

        /*
            We have reached the point where divisor > dividend,
            therefore divide divisor and quotient by two ... or times 5/10
        */
        tmp_divisor = 5*tmp_divisor; // times 5 ...
        quotient = 5*quotient; // times 5 ...
        tmp_divisor.snum.erase(tmp_divisor.snum.size()-1); // and divide by 10
        quotient.snum.erase(quotient.snum.size()-1); // and divide by 10

        /*
            Now call get_quotient RECURSIVEly for the difference ...
            ... to get the exact quotient
        */
        quotient = quotient + division( (dividend-tmp_divisor), divisor, remain );
    }

    return quotient;
}

// returns quotient and remaider via the struc QuoRem ...
QuoRem operator / ( const BigInt& dividend, const BigInt& divisor )
{
    QuoRem qr;
    if( divisor.snum == "0" )
    {
        qr.quo.snum = "Error! Division by ZERO is NOT defined!";;
        return qr;
    }

    BigInt s, remain;
    if( dividend.sign == divisor.sign )
    {
        if( dividend.sign == '+' )
            s = division( dividend, divisor, remain );
        else
            s = division( -dividend, -divisor, remain );

        s.sign = '+';
    }
    else // signs are different ...
    {
        if( dividend.sign == '-' )
            s = division( -dividend, divisor, remain );
        else
            s = division( dividend, -divisor, remain );

        s.sign = '-';
        remain.sign = '-';
    }

    if( s.snum == "0" ) s.sign = '+';
    if( remain.snum == "0" ) remain.sign = '+';

    qr.quo = s;
    qr.rem = remain;
    return qr;
}





int main()
{
    StrInt s1( "1090890809890809780970968907608709780987098098790709709709789290809870980989308098309809389038093809380938093803983098" );
    StrInt s2( "5008908908908908908080789789790879078907070979070790707070707097097087080989028092809280928209820982098209802980298092809" );
    StrInt s3 = s1 + s2;
    
    cout << s2 << "+" << s1 << "=" << s2+s1 << endl << endl;
    
    cout << s1 << "*" << s2 << "=" << s1*s2 << endl;
    cout << s2 << "*" << s1 << "=" << s2*s1 << endl;

    cout << endl;

    for( int i = 0; i < 3; ++i )
    {
        StrInt s3(i*1000000000); // i * 10^10
        cout << s1 << "*" << s3 << "=" << s1*s3 << endl;
        cout << s3 << "*" << s1 << "=" << s3*s1 << endl;
    }
    
    QuoRem qr; // to hold quotient and remainder for division returned values

        qr = s1/s2;
        cout << s1 << "/" << s2 << "=" << qr.quo << ", remainder="
             << qr.rem << endl;

}
