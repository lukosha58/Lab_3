#include <UnitTest++/UnitTest++.h>

#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/2/encrypt.cpp"
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/2/Exception.h"
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/2/Exception.cpp"
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/2/encrypt.h"
SUITE(EncodeCipher)
{
    const int key = 3;
    Encrypt test(key);
    TEST(B) {
        wstring open_text = L"ПРИВЕТ";
        wstring result_correct = L"ПВРЕИТ";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(mal) {
        wstring open_text = L"привет";
        wstring result_correct = L"пвреит";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(B_L) {
        wstring open_text = L"HELLO";
        wstring result_correct = L"HLEOL";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(min) {
        wstring open_text = L"hello";
        wstring result_correct = L"hleol";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(mix) {
        wstring open_text = L"приbbet";
        wstring result_correct = L"пbtрb иe";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(simvol) {
        wstring open_text = L"!\"№;%:";
        wstring result_correct = L"!;\"%№:";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(cifr) {
        wstring open_text = L"23434134";
        wstring result_correct = L"23334441";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
    TEST(all) {
        wstring open_text = L"hello мир%123";
        wstring result_correct = L"hlм%3eoи1 l р2";
        CHECK_EQUAL(true, result_correct == test.EncodeCipher(test,open_text));
    }
}
SUITE(decshifr)
{
    const int key = 3;
    Encrypt test(key);
    TEST(B) {
        wstring cipher_text = L"ПВРЕИТ";
        wstring result_correct = L"ПРИВЕТ";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(m) {
        wstring cipher_text = L"пвреит";
        wstring result_correct = L"привет";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(Eng) {
        wstring cipher_text = L"HELLO";
        wstring result_correct = L"HLEOL";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(min) {
        wstring cipher_text = L"hello";
        wstring result_correct = L"hleol";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(mix) {
        wstring cipher_text = L"приbbet";
        wstring result_correct = L"пbtрb иe";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(simvol) {
        wstring cipher_text = L"!;\"%№:";
        wstring result_correct = L"!\"№;%:";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(cifr) {
        wstring cipher_text = L"23334441";
        wstring result_correct = L"23434134";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
    TEST(all) {
        wstring cipher_text = L"hello мир%123";
        wstring result_correct = L"hlм%3eoи1 l р2";
        CHECK_EQUAL(true, result_correct == test.DecodeCipher(test,cipher_text));
    }
}

int main()
{
    return UnitTest::RunAllTests();
}