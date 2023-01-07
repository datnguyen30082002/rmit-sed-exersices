#pragma once
#include "Header.h"
#include "RentDate.h"

class Review
{
private:
    int reviewId;
    int reviewHouseId;
    string reviewer;
    int score = 0;
    string comment = "";
    RentDate reviewDate;
    string houseOwner;
    int ownerScore = 0;
    string ownerComment = "";
    RentDate ownerReviewDate;
    bool ownerWriteReview = false;

public:
    Review();

    Review(int reviewId, int reviewHouseId, string reviewer, int score, string comment, RentDate reviewDate);

    int getReviewId();

    void setReviewId(int reviewId);

    int getReviewHouseId();

    void setReviewHouseId(int reviewHouseId);

    string getReviewer();

    void setReviewer(string reviewer);

    int getReviewScore();

    void setReviewScore(int score);

    string getReviewComment();

    void setReviewComment(string comment);

    RentDate getReviewDate();

    void setReviewDate(RentDate reviewDate);

    string getHouseOwner();

    void setHouseOwner(string houseOwner);

    int getOwnerScore();

    void setOwnerScore(int score);

    string getOwnerComment();

    void setOwnerComment(string comment);

    RentDate getOwnerReviewDate();

    void setOwnerReviewDate(RentDate reviewDate);

    bool getOwnerWriteReview();

    void setOwnerWriteReview(bool ownerWriteReview);

    void showOccupierReview();

    void showOwnerReview();
};

void showAllReviewHeader();

void showAllOccupierReviewInfo(vector<Review*> reviews);

void showAllOwnerReviewInfo(vector<Review*> reviews);