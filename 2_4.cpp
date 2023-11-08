#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double riverWidth, downstreamDistance, costUnderwater, costOverland;
    cout << "Enter the width of the river (in meters): ";
    cin >> riverWidth;
    cout << "Enter the distance of the factory downstream on the other side of the river (in meters): ";
    cin >> downstreamDistance;
    cout << "Enter the unit cost of laying the power line underwater (per meter): ";
    cin >> costUnderwater;
    cout << "Enter the unit cost of laying the power line overland (per meter): ";
    cin >> costOverland;

    double minTotalCost = 1000000000000000;
    double optimalUnderwaterLength = 0.0;
    double optimalOverlandLength = 0.0;

    // Try every possible x from 0 to the downstreamDistance
    for (int x = 0; x <= downstreamDistance; ++x) {
        double underwaterLength = sqrt(pow(riverWidth, 2) + pow(x, 2));
        double overlandLength = downstreamDistance - x;
        double totalCost = underwaterLength * costUnderwater + overlandLength * costOverland;

        if (totalCost < minTotalCost) {
            minTotalCost = totalCost;
            optimalUnderwaterLength = underwaterLength;
            optimalOverlandLength = overlandLength;
        }
    }

    cout << fixed << setprecision(1); // Set precision for output
    cout << "The power line should run " << optimalUnderwaterLength
         << " meters under water and " << optimalOverlandLength
         << " meters overland for a minimum total cost." << endl;
    cout << "The total cost of constructing the power line is $" << minTotalCost << endl;

    return 0;
}
