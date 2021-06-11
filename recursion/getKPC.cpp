// public static ArrayList<String> getKPC(String str) {
//         return null;
//     }

/*
    0 -> .;
    1 -> abc
    2 -> def
    3 -> ghi
    4 -> jkl
    5 -> mno
    6 -> pqrs
    7 -> tu
    8 -> vwx
    9 -> yz
*/

#include<bits/stdc++.h>
using namespace std;

void solver(int index, string &temp, unordered_map<int, string> &mp, vector<string> &res, string &s) {
	if (index == s.size()) {
		res.push_back(temp);
		return;
	}
	string curr = mp[s[index] - '0'];
	for (char cVal : curr) {
		temp += cVal;
		solver(index + 1, temp, mp, res, s);
		temp.erase(temp.size() - 1);
	}
}

void printSol(vector<string> &res) {
	cout << "[";
	int i = 0;
	for (i = 0; i < (int)res.size() - 1; i++) {
		cout << res[i] << ", ";
	}


	cout << res[i] << "]\n";
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s = "";
	cin >> s;
	unordered_map<int, string> mp;
	mp[0] = ".;";
	mp[1] = "abc"; mp[2] = "def"; mp[3] = "ghi"; mp[4] = "jkl"; mp[5] = "mno"; mp[6] = "pqrs"; mp[7] = "tu"; mp[8] = "vwx"; mp[9] = "yz";

	vector<string> res;
	string temp = "";
	if (s.size() > 0)
		solver(0, temp, mp, res, s);

	printSol(res);
	return 0;
}

/*
//java solution

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);

        String inp = scn.nextLine();

        System.out.println(getKPC(inp));
    }

    public static String[] t = {
        ".;",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tu",
        "vwx",
        "yz"
    };
    public static ArrayList < String > getKPC(String str) {


        ArrayList < String > res = new ArrayList < > ();
        gkUtil(0,"",res, str);

        return res;
    }

    public static void gkUtil(int idx, String temp, ArrayList<String> res, String str) {

        if (idx == str.length()) {
            res.add(temp);
            return;
        }

        //keyPad Index = kpIdx
        int kpIdx = Integer.parseInt(str.charAt(idx) + "");

        for (int i = 0; i < t[kpIdx].length(); i++) {
            gkUtil(idx + 1, temp + t[kpIdx].charAt(i), res, str);
        }
    }

}

//part 2: print kpc
//code
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);

        String inp = scn.nextLine();

        printKPC(inp);
    }

    public static String[] t = {
        ".;",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tu",
        "vwx",
        "yz"
    };
    public static void printKPC(String str) {
        gkUtil(0,"", str);  //get kpc util = gkUtil

        // return res;
    }

    public static void gkUtil(int idx, String temp, String str) {

        if (idx == str.length()) {

            // res.add(temp);
            System.out.println(temp);
            return;
        }

        //keyPad Index = kpIdx
        int kpIdx = Integer.parseInt(str.charAt(idx) + "");

        for (int i = 0; i < t[kpIdx].length(); i++) {
            gkUtil(idx + 1, temp + t[kpIdx].charAt(i), str);
        }
    }

}

*/