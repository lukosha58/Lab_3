#include <UnitTest++/UnitTest++.h>
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/1/modAlphaCipher.h"
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/1/modAlphaCipher.cpp"
#include "/home/user/Documents/TIMP_Lab/Lab_2/Lab_2/1/Exception.h"

SUITE(kl_tst)
{
    TEST(B) {
        modAlphaCipher test(L"ФЫВА");
        CHECK(true);
    }

    TEST(mal) {
        modAlphaCipher test(L"фыва");
        CHECK(true);
    }

    TEST(B_mal) {
        modAlphaCipher test(L"фыВА");
        CHECK(true);
    }
    TEST(num) {
        CHECK_THROW(modAlphaCipher test(L"ыфв54ывф"),Error);
    }
    TEST(probel) {
        CHECK_THROW(modAlphaCipher test(L"ф ы"), Error);
    }
    TEST(simbol) {
        CHECK_THROW(modAlphaCipher test(L"Па().1!»№»!"),Error);
    }
    TEST(pusto) {
        CHECK_THROW(modAlphaCipher test(L""), Error);
    }



}

struct KeyAB_fixture { // Для тестов шифрования и расшифрования
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"МЕЧ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};

SUITE(enshifr)
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV ) {
        wstring open_text = L"ПРИВЕТ";
        wstring result_correct = L"ЬХАОЙЙ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki ) {
        wstring open_text = L"привет";
        wstring result_correct = L"ЬХАОЙЙ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig ) {
        wstring open_text = L"пРиВеТ";
        wstring result_correct = L"ЬХАОЙЙ";
        CHECK_EQUAL(true, result_correct == pointer->encrypt(open_text));
    }
    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota ) {
        wstring open_text = L"";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num) {
        wstring open_text = L"ПРИВЕТ123";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring open_text = L"ПРИВЕТ*!";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring open_text = L"ПРИ ВЕТ";
        CHECK_THROW(pointer->encrypt(open_text),Error);
    }

}
SUITE(decshifr)
{
    TEST_FIXTURE(KeyAB_fixture, BOLSHIE_BUKV) {
        wstring cipher_text = L"ЬХАОЙЙ";
        wstring result_correct = L"ПРИВЕТ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, malehenkie_bukovki) {
        wstring cipher_text = L"ЬХАОЙЙ";
        wstring result_correct = L"ПРИВЕТ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }
    TEST_FIXTURE(KeyAB_fixture, littleBig) {
        wstring cipher_text = L"ЬХАОЙЙ";
        wstring result_correct = L"ПРИВЕТ";
        CHECK_EQUAL(true, result_correct == pointer->decrypt(cipher_text));
    }

    TEST_FIXTURE(KeyAB_fixture, iscluch_pustota) {
        wstring cipher_text = L"";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_num ) {
        wstring cipher_text = L"ПРИВЕТ123";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_special_simbol) {
        wstring cipher_text = L"ПРИВЕТ*!";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
    TEST_FIXTURE(KeyAB_fixture,iscluch_mix_probel) {
        wstring cipher_text = L"ПРИ ВЕТ";
        CHECK_THROW(pointer->decrypt(cipher_text),Error);
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}