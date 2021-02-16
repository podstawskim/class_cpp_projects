#include "TextWrap.h"
#include <gtest/gtest.h>

TEST(TextWrap, Constructor) {

    TextWrap textWrap{};
}

TEST(TextWrap, Constructor_PassNumberOfColumnsUsingConstor) {

    TextWrap textWrap{2};
}

TEST(TextWrap, Wrap_OneCharacterInOneColumns) {

    TextWrap textWrap{1};

    EXPECT_EQ("a", textWrap.wrap("a"));
}

TEST(TextWrap, Wrap_OneCharacterInOneColumns_OtherCharacter) {

    TextWrap textWrap{1};

    EXPECT_EQ("b", textWrap.wrap("b"));
}

TEST(TextWrap, Wrap_TwoCharacterInOneColumns) {

    TextWrap textWrap{1};

    EXPECT_EQ("a\nb", textWrap.wrap("ab"));
}

TEST(TextWrap, Wrap_FourCharacterInTwoColumns) {

    TextWrap textWrap{2};

    EXPECT_EQ("ab\ncd", textWrap.wrap("abcd"));
}
TEST(TextWrap, Wrap_Two3CharactersLongWords)
{
    TextWrap textWrap{3};
    EXPECT_EQ("abc\nabc", textWrap.wrap("abc abc"));
}
TEST(TextWrap, Wrap_WrapTwoWordsOfDifferentLenghts)
{
    TextWrap textWrap{5};
    EXPECT_EQ("foone\nfoneee", textWrap.wrap("foone foneee"));
}

TEST(TextWrap, Wrap_WrapThreeWords)
{
    TextWrap textWrap{3};
    EXPECT_EQ("foo\nbar\nbaz", textWrap.wrap("foo bar baz"));
}
TEST(TextWrap, WrapLoremIpsumWith50Columns)
{
    TextWrap textWrap{50};
    const char* text = {
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."

    };
    const char* wrappedText{
        "Lorem ipsum dolor sit amet, consectetur adipiscing\n"
        "elit. Duis accumsan dignissim ante vel suscipit.\n"
        "Aenean suscipit ex porttitor, lobortis eros non,\n"
        "cursus nunc. In consectetur, magna nec sodales\n"
        "egestas, nisi felis tincidunt ipsum, et ornare\n"
        "massa magna sit amet eros. Etiam bibendum eros\n"
        "viverra augue ultrices vehicula. Etiam risus\n"
        "lectus, rhoncus vitae odio eget, sagittis\n"
        "malesuada nisl. Phasellus accumsan mi lorem, eget\n"
        "finibus purus pulvinar nec. Aliquam consequat\n"
        "ligula et maximus lobortis. In volutpat libero\n"
        "vitae eros gravida aliquet. Interdum et malesuada\n"
        "fames ac ante ipsum primis in faucibus. Fusce ac\n"
        "felis sapien. Nulla at lacus non risus imperdiet\n"
        "bibendum sit amet molestie purus. Nunc quis rutrum\n"
        "est. Sed id nisl non tortor facilisis rhoncus."
    };
    EXPECT_EQ(wrappedText, textWrap.wrap(text));

}

TEST(TextWrap, WrapLoremIpsumWith80Columns)
{
    TextWrap textWrap{80};
    const char* text = {
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."

    };
    const char* wrappedText{
          "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim\n"
          "ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc.\n"
          "In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare\n"
          "massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula.\n"
          "Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus\n"
          "accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et\n"
          "maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et\n"
          "malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla\n"
          "at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum\n"
          "est. Sed id nisl non tortor facilisis rhoncus."
    };
    EXPECT_EQ(wrappedText, textWrap.wrap(text));

}

TEST(TextWrap, WrapLoremIpsumWith100Columns)
{
    TextWrap textWrap{100};
    const char* text = {
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit. Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."

    };
    const char* wrappedText{
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis accumsan dignissim ante vel suscipit.\n"
            "Aenean suscipit ex porttitor, lobortis eros non, cursus nunc. In consectetur, magna nec sodales\n"
            "egestas, nisi felis tincidunt ipsum, et ornare massa magna sit amet eros. Etiam bibendum eros\n"
            "viverra augue ultrices vehicula. Etiam risus lectus, rhoncus vitae odio eget, sagittis malesuada\n"
            "nisl. Phasellus accumsan mi lorem, eget finibus purus pulvinar nec. Aliquam consequat ligula et\n"
            "maximus lobortis. In volutpat libero vitae eros gravida aliquet. Interdum et malesuada fames ac ante\n"
            "ipsum primis in faucibus. Fusce ac felis sapien. Nulla at lacus non risus imperdiet bibendum sit\n"
            "amet molestie purus. Nunc quis rutrum est. Sed id nisl non tortor facilisis rhoncus."
    };
    EXPECT_EQ(wrappedText, textWrap.wrap(text));

}

