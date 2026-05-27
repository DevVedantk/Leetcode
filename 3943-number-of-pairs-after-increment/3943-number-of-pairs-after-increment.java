class Solution {

    public int[] numberOfPairs(int[] nums1, int[] nums2, int[][] q) {

        int n = nums2.length;
        int len = (int)Math.sqrt(n) + 1;

        long[] arr = new long[n];

        for(int i = 0; i < n; i++) {
            arr[i] = nums2[i];
        }

        ArrayList<HashMap<Long,Integer>> mp = new ArrayList<>();

        for(int i = 0; i < len; i++) {
            mp.add(new HashMap<>());
        }

        long[] lazy = new long[len];

        for(int i = 0; i < n; i++) {
            HashMap<Long,Integer> cur = mp.get(i / len);
            cur.put(arr[i], cur.getOrDefault(arr[i], 0) + 1);
        }

        ArrayList<Integer> ans = new ArrayList<>();

        for(int[] qq : q) {

            // update query
            if(qq.length == 4) {

                int l = qq[1];
                int r = qq[2];
                long val = qq[3];

                while(l <= r && l % len != 0) {

                    int b = l / len;

                    HashMap<Long,Integer> cur = mp.get(b);

                    long oldVal = arr[l];

                    cur.put(oldVal, cur.get(oldVal) - 1);

                    if(cur.get(oldVal) == 0) {
                        cur.remove(oldVal);
                    }

                    arr[l] += val;

                    cur.put(arr[l], cur.getOrDefault(arr[l], 0) + 1);

                    l++;
                }

                while(l <= r && (r + 1) % len != 0) {

                    int b = r / len;

                    HashMap<Long,Integer> cur = mp.get(b);

                    long oldVal = arr[r];

                    cur.put(oldVal, cur.get(oldVal) - 1);

                    if(cur.get(oldVal) == 0) {
                        cur.remove(oldVal);
                    }

                    arr[r] += val;

                    cur.put(arr[r], cur.getOrDefault(arr[r], 0) + 1);

                    r--;
                }

                while(l <= r) {
                    lazy[l / len] += val;
                    l += len;
                }

            } else {

                long tot = qq[1];

                int cnt = 0;

                for(int x : nums1) {

                    long needBase = tot - x;

                    for(int b = 0; b < mp.size(); b++) {

                        HashMap<Long,Integer> cur = mp.get(b);

                        cnt += cur.getOrDefault(needBase - lazy[b], 0);
                    }
                }

                ans.add(cnt);
            }
        }

        int[] res = new int[ans.size()];

        for(int i = 0; i < ans.size(); i++) {
            res[i] = ans.get(i);
        }

        return res;
    }
}