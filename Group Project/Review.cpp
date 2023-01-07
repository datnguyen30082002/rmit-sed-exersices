#include "Review.h"

Review::Review() {};

Review::Review(int reviewId, int reviewHouseId, string reviewer, int score, string comment, RentDate reviewDate)
{
	this->reviewId = reviewId;
	this->reviewHouseId = reviewHouseId;
	this->reviewer = reviewer;
	this->score = score;
	this->comment = comment;
	this->reviewDate = reviewDate;
}

int Review::getReviewId()
{
	return this->reviewId;
}

void Review::setReviewId(int reviewId)
{
	this->reviewId = reviewId;
}

int Review::getReviewHouseId()
{
	return this->reviewHouseId;
}

void Review::setReviewHouseId(int reviewHouseId)
{
	this->reviewHouseId = reviewHouseId;
}

string Review::getReviewer()
{
	return this->reviewer;
}

void Review::setReviewer(string reviewer)
{
	this->reviewer = reviewer;
}

int Review::getReviewScore()
{
	return this->score;
}

void Review::setReviewScore(int score)
{
	this->score = score;
}

string Review::getReviewComment()
{
	return this->comment;
}

void Review::setReviewComment(string comment)
{
	this->comment = comment;
}

RentDate Review::getReviewDate()
{
	return this->reviewDate;
}

void Review::setReviewDate(RentDate reviewDate)
{
	this->reviewDate = reviewDate;
}

string Review::getHouseOwner()
{
	return this->houseOwner;
}

void Review::setHouseOwner(string houseOwner)
{
	this->houseOwner = houseOwner;
}

int Review::getOwnerScore()
{
	return this->ownerScore;
}

void Review::setOwnerScore(int ownerScore)
{
	this->ownerScore = ownerScore;
}

string Review::getOwnerComment()
{
	return this->ownerComment;
}

void Review::setOwnerComment(string ownerComment)
{
	this->ownerComment = ownerComment;
}

RentDate Review::getOwnerReviewDate()
{
	return this->ownerReviewDate;
}

void Review::setOwnerReviewDate(RentDate ownerReviewDate)
{
	this->ownerReviewDate = ownerReviewDate;
}

bool Review::getOwnerWriteReview()
{
	return this->ownerWriteReview;
}

void Review::setOwnerWriteReview(bool ownerWriteReview)
{
	this->ownerWriteReview = ownerWriteReview;
}

void Review::showOccupierReview()
{
	cout.width(REVIEW_ID);
	cout << left << reviewId;
	cout.width(REVIEW_HOUSE_ID);
	cout << left << reviewHouseId;
	cout.width(REVIEWER);
	cout << left << reviewer;
	cout.width(REVIEW_SCORE);
	cout << left << score;
	cout.width(REVIEW_COMMENT);
	cout << left << comment;
	cout.width(REVIEW_DATE);
	this->reviewDate.showDateInfo();
}

void Review::showOwnerReview()
{
	cout.width(REVIEW_ID);
	cout << left << reviewId;
	cout.width(REVIEW_HOUSE_ID);
	cout << left << reviewHouseId;
	cout.width(REVIEWER);
	cout << left << houseOwner;
	cout.width(REVIEW_SCORE);
	cout << left << ownerScore;
	cout.width(REVIEW_COMMENT);
	cout << left << ownerComment;
	cout.width(REVIEW_DATE);
	this->ownerReviewDate.showDateInfo();
}

void showAllReviewHeader()
{
	cout << endl;
	cout << "-------------------- Review --------------------" << endl;
	cout.width(REVIEW_ID);
	cout << left << "Review ID";
	cout.width(REVIEW_HOUSE_ID);
	cout << left << "Review House ID";
	cout.width(REVIEWER);
	cout << left << "Reviewer";
	cout.width(REVIEW_SCORE);
	cout << left << "Review Score";
	cout.width(REVIEW_COMMENT);
	cout << left << "Review Comment";
	cout.width(REVIEW_DATE);
	cout << left << "Review Date";
}

void showAllOccupierReviewInfo(vector<Review*> reviews)
{
	showAllReviewHeader();
	for (int i = 0; i < reviews.size(); i++)
	{
		cout << endl;
		reviews[i]->showOccupierReview();
	}
}

void showAllOwnerReviewInfo(vector<Review*> reviews)
{
	showAllReviewHeader();
	for (int i = 0; i < reviews.size(); i++)
	{
		cout << endl;
		reviews[i]->showOwnerReview();
	}
}