#include <gtest/gtest.h>

#include "TrieTree.h"

const std::set<std::string> wordsWithSamePrefix{
    "Apple",      "Ant",        "Airplane",     "Artist",   "Amazing",   "Adventure",
    "Armor",      "Alert",      "Anchor",       "Arrow",    "Animal",    "Absolute",
    "Ancient",    "Attack",     "Ability",      "Area",     "Atom",      "Album",
    "Assist",     "Avenue",     "Arrange",      "Argument", "Ambition",  "Approve",
    "Accurate",   "Affection",  "Active",       "Abandon",  "Absorb",    "Abundant",
    "Abstract",   "Accomplish", "Adapt",        "Address",  "Admire",    "Admit",
    "Advertise",  "Affair",     "Afford",       "Agony",    "Agree",     "Aid",
    "Aim",        "Alarm",      "Align",        "Allow",    "Alphabet",  "Alter",
    "Amuse",      "Analyze",    "Announce",     "Annual",   "Another",   "Answer",
    "Anticipate", "Anxiety",    "Apart",        "Apology",  "Appear",    "Apply",
    "Appoint",    "Appreciate", "Approachable", "April",    "Arch",      "Argue",
    "Arise",      "Armchair",   "Arrangement",  "Arrest",   "Arrive",    "Article",
    "Artificial", "Artistic",   "Ashamed",      "Assemble", "Assert",    "Assess",
    "Assign",     "Assist",     "Associate",    "Assume",   "Assure",    "Astonish",
    "Athlete",    "Atmosphere", "Attach",       "Attempt",  "Attitude",  "Attorney",
    "Attract",    "Audience",   "Authentic",    "Author",   "Authority", "Automatic",
    "Available",  "Average",    "Award",        "Awesome",
};

const std::set<std::string> wordsWithDifferentPrefix{
    "Automobile",    "Bicycle",      "Counterattack",     "Disconnect",     "Export",
    "Forecast",      "Geography",    "Hyperactive",       "International",  "Macroscope",
    "Microwave",     "Multitask",    "Overload",          "Postpone",       "Preview",
    "Rewrite",       "Submarine",    "Superpower",        "Transform",      "Unexpected",
    "Underground",   "Antivirus",    "Cooperate",         "Decode",         "Encourage",
    "Illegal",       "Impossible",   "Invisible",         "Irregular",      "Malfunction",
    "Misunderstand", "Nonfiction",   "Outperform",        "Overachieve",    "Perceive",
    "Proactive",     "Semicircle",   "Triangle",          "Ultraviolet",    "Underestimate",
    "Withdraw",      "Foresee",      "Dissatisfied",      "Extract",        "Prehistoric",
    "Reevaluate",    "Subtitle",     "Superhuman",        "Transmit",       "Uncertain",
    "Automatic",     "Bilingual",    "Counterproductive", "Disapprove",     "Exaggerate",
    "Forethought",   "Hyperlink",    "Interpersonal",     "Macroeconomics", "Microchip",
    "Multimedia",    "Overcome",     "Postgraduate",      "Prerequisite",   "Recycle",
    "Subconscious",  "Supernatural", "Transaction",       "Unbelievable",   "Underdeveloped",
    "Antisocial",    "Coexist",      "Deactivate",        "Enlighten",      "Illiterate",
    "Immature",      "Independent",  "Irresponsible",     "Malnutrition",   "Mislead",
    "Nontoxic",      "Outsource",    "Overestimate",      "Performance",    "Proceed",
    "Semifinal",     "Tripod",       "Ultrasound",        "Underrated",     "Withhold",
    "Forewarn",      "Disbelief",    "Exceptional",       "Predict",        "Regenerate",
    "Subject",       "Superhero",    "Translate",         "Unfinished",     "Undercover",
};

TEST(TrueTree, BaseInsert)
{
	std::string word{"base"};
	TrieTree trieTree;
	trieTree.insert(word);
	EXPECT_TRUE(trieTree.search(word));
	EXPECT_TRUE(trieTree.startsWith("b"));
	EXPECT_TRUE(trieTree.startsWith("ba"));
	EXPECT_TRUE(trieTree.startsWith("bas"));
	EXPECT_TRUE(trieTree.startsWith("base"));
}

TEST(TrueTree, InsertEmptyWord)
{
	std::string word{""};
	TrieTree trieTree;
	EXPECT_THROW(trieTree.insert(word), std::underflow_error);
}

TEST(TrueTree, SearchEmptyWord)
{
	std::string word{""};
	TrieTree trieTree;
	EXPECT_FALSE(trieTree.search(word));
}

TEST(TrueTree, StartsWithEmptyWord)
{
	std::string word{""};
	TrieTree trieTree;
	EXPECT_TRUE(trieTree.startsWith(word));
}

TEST(TrueTree, BaseRemove)
{
	std::string word{"base"};
	TrieTree trieTree;
	trieTree.insert(word);
	EXPECT_TRUE(trieTree.startsWith("base"));
	trieTree.remove(word);
	EXPECT_FALSE(trieTree.startsWith("base"));
}

TEST(TrueTree, RemoveEmptyWord)
{
	std::string word{""};
	TrieTree trieTree;
	EXPECT_THROW(trieTree.remove(word), std::underflow_error);
}

TEST(TrueTree, WoredWithSamePrefix)
{
	TrieTree trieTree;

	for (const auto &w : wordsWithSamePrefix) {
		trieTree.insert(w);
	}
	for (const auto &w : wordsWithSamePrefix) {
		EXPECT_TRUE(trieTree.search(w));

		std::string prefix;
		for (const auto &c : w) {
			prefix.push_back(c);
			EXPECT_TRUE(trieTree.startsWith(prefix));
		}
	}

	for (const auto &w : wordsWithSamePrefix) {
		trieTree.remove(w);
	}
	for (const auto &w : wordsWithSamePrefix) {
		EXPECT_FALSE(trieTree.search(w));

		std::string prefix;
		for (const auto &c : w) {
			prefix.push_back(c);
			EXPECT_FALSE(trieTree.startsWith(prefix));
		}
	}
}

TEST(TrueTree, WoredWithDifferentPrefix)
{
	TrieTree trieTree;

	for (const auto &w : wordsWithDifferentPrefix) {
		trieTree.insert(w);
	}
	for (const auto &w : wordsWithDifferentPrefix) {
		EXPECT_TRUE(trieTree.search(w));

		std::string prefix;
		for (const auto &c : w) {
			prefix.push_back(c);
			EXPECT_TRUE(trieTree.startsWith(prefix));
		}
	}

	for (const auto &w : wordsWithDifferentPrefix) {
		trieTree.remove(w);
	}
	for (const auto &w : wordsWithDifferentPrefix) {
		EXPECT_FALSE(trieTree.search(w));

		std::string prefix;
		for (const auto &c : w) {
			prefix.push_back(c);
			EXPECT_FALSE(trieTree.startsWith(prefix));
		}
	}
}

TEST(TrueTree, BasePropose)
{
	std::string word{"base"};
	TrieTree trieTree;
	trieTree.insert(word);
	EXPECT_EQ(trieTree.propose("b"), word);
	EXPECT_EQ(trieTree.propose("ba"), word);
	EXPECT_EQ(trieTree.propose("bas"), word);
	EXPECT_EQ(trieTree.propose("base"), word);
}

TEST(TrueTree, InvalidPropose)
{
	std::string word{"base"};
	TrieTree trieTree;
	trieTree.insert(word);
	EXPECT_EQ(trieTree.propose("k"), "k");
	EXPECT_EQ(trieTree.propose(""), "base");
}

TEST(TrueTree, FewWordsPropose)
{
	std::string word{"base"};
	TrieTree trieTree;
	trieTree.insert("baaaa");
	trieTree.insert("bbaaa");
	trieTree.insert("bbbaa");
	trieTree.insert("bc");
	EXPECT_EQ(trieTree.propose("b"), "baaaa");
	EXPECT_EQ(trieTree.propose("ba"), "baaaa");
	EXPECT_EQ(trieTree.propose("bb"), "bbaaa");
	EXPECT_EQ(trieTree.propose("bc"), "bc");
}
