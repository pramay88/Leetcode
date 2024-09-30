class Bucket {
    public int count;
    public Set<String> keys;
    public Bucket prev, next;
    
    public Bucket(int c) {
        count = c;
        keys = new HashSet<>();
        prev = next = null;
    }
}

class AllOne {
    private Map<String, Integer> key2count;
    private Map<Integer, Bucket> count2bucket;
    private Bucket head, tail;

    public AllOne() {
        key2count = new HashMap<>();
        count2bucket = new HashMap<>();
        head = new Bucket(Integer.MIN_VALUE);
        tail = new Bucket(Integer.MAX_VALUE);
        head.next = tail;
        tail.prev = head;
    }
    
    public void inc(String key) {
        if (!key2count.containsKey(key)) {
            key2count.put(key, 1);
            if (!count2bucket.containsKey(1)) {
                count2bucket.put(1, new Bucket(1));
                insertBucketAfter(count2bucket.get(1), head);
            }
            count2bucket.get(1).keys.add(key);
        } else {
            changeKey(key, 1);
        }
    }
    
    public void dec(String key) {
        if (key2count.containsKey(key)) {
            int count = key2count.get(key);
            if (count == 1) {
                key2count.remove(key);
                removeKeyFromBucket(count2bucket.get(count), key);
            } else {
                changeKey(key, -1);
            }
        }
    }
    
    public String getMaxKey() {
        return tail.prev == head ? "" : tail.prev.keys.iterator().next();
    }
    
    public String getMinKey() {
        return head.next == tail ? "" : head.next.keys.iterator().next();
    }
    
    private void changeKey(String key, int offset) {
        int oldCount = key2count.get(key);
        int newCount = oldCount + offset;
        key2count.put(key, newCount);
        
        Bucket oldBucket = count2bucket.get(oldCount);
        
        if (!count2bucket.containsKey(newCount)) {
            count2bucket.put(newCount, new Bucket(newCount));
            insertBucketAfter(count2bucket.get(newCount), offset == 1 ? oldBucket : oldBucket.prev);
        }
        
        count2bucket.get(newCount).keys.add(key);
        removeKeyFromBucket(oldBucket, key);
    }
    
    private void removeKeyFromBucket(Bucket bucket, String key) {
        bucket.keys.remove(key);
        if (bucket.keys.isEmpty()) {
            removeBucketFromList(bucket);
            count2bucket.remove(bucket.count);
        }
    }
    
    private void removeBucketFromList(Bucket bucket) {
        bucket.prev.next = bucket.next;
        bucket.next.prev = bucket.prev;
        bucket.prev = null;
        bucket.next = null;
    }
    
    private void insertBucketAfter(Bucket newBucket, Bucket prevBucket) {
        newBucket.prev = prevBucket;
        newBucket.next = prevBucket.next;
        prevBucket.next.prev = newBucket;
        prevBucket.next = newBucket;
    }
}


/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * String param_3 = obj.getMaxKey();
 * String param_4 = obj.getMinKey();
 */