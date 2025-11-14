/*

    void pointer data type na jene datar jnno memory allocate krte pare,
    pore pointer value k jkno data type e typecast kora jai.


    malloc & calloc function returns a void pointer.
    so era data chara memory allocate krte pare.

*/

#include <stdio.h>

int main()
{
    int n = 10;
    void *ptr;

    ptr = &n;

    // printf("%d", *ptr); ❌  (value er data type compiler k janate hbe, jate compiler bujte pare kototuko memory allocate krte hbe, tai typecast krte hbe)
    printf("%d", *(int *)ptr);

    // printf("%p", ptr); ✅  (sokol pointer eki size er address store kore(64 bit or 8 byte), tai data type lagena, compiler emenetei jane j etar size 64 bit/8byte)
    return 0;
}

/*

    value print করার সময় compiler কে data type জানাতে হয়,
    কারণ ভিন্ন ভিন্ন type এর data ভিন্ন ভিন্ন memory size দখল করে।
    তাই compiler কে বলা লাগে কত byte পড়তে হবে।

    কিন্তু address print করার সময় type জানা লাগে না,
    কারণ সব pointer variable একই আকারের address store করে
    (যেমন 64-bit system এ প্রতিটি pointer 8 byte)।
    তাই address প্রিন্ট করতে data type প্রয়োজন হয় না।


*/


#include <stdio.h>

int add(int *x)
{
    *x = 20;
    return *x;
}

int main()
{
    int a = 10;
    printf("%d\n", a);

    int b = add(&a);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}