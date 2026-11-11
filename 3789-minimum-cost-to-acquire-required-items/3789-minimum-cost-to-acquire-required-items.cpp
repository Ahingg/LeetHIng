class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // cek apakah cost1 + cost2 < costBoth, -> costBoth
        // costBoth bisa dipakai sampai dimana x = min(need1, need2), maka sisanya tingal cost * sisaNeed

        // tapi bisa aja kita tinggal total*max, tapi apakah ini selalu hasil paling optimalnya?
        // karena bisa aja total * max, yang bagian terkecil itu dibeli secara sia sia, kita harus tau apakah setelah dananya melebihi disini itu masih lebih worth it kalau kita pakai yang prioritas ke kecil.
        long long total = 0;
        if(cost1 + cost2 > costBoth) {
            // karena gw males cek if elsenya langsung bandingin hasil akhirnyua aja
            long long total1 = (1LL * min(need1, need2) * costBoth);
            if(need1 > need2) total1 += (1LL * (need1 - need2) * cost1);
            else total1 += (1LL * (need2 - need1) * cost2);

            long long total2 = (1LL * max(need1, need2) * costBoth);
            total = min(total1, total2);
        }
        else {
            total += (1LL * cost1 * need1) + (1LL * cost2 * need2);
        }
        return total;
    }

};