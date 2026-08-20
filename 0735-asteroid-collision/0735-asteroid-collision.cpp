class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        //lets iterate on the asteroids

        for(int curr:asteroids)
        {
            // we will set our cuuent asteroid as alive
            bool alive  = true;

            //now is suppose collison there so we need to resolve it
            while(alive && !st.empty() && st.top()>0 && curr<0)
            {
                // we need to resolve and lets see if the current asteriod survives the collision

                if(st.top() < abs(curr))
                {
                    st.pop();
                }
                else if(st.top() == abs(curr))
                {
                    st.pop();
                    alive = false;//both will explode na
                }
                else
                {
                    // current dies
                    alive = false;//updating the status of current status of asteroid
                }
            }
            // if suppose the current asterioid survives collsion and status of alive true so push in stack
            if(alive)
            {
                //like if status is alive tab hiii
               st.push(curr);
            }   
        }

        // next lets push all from stack to vector
        vector<int>res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        //need to reverse it
        reverse(res.begin(),res.end());
        return res;
    }
};
/* we have to tell the state of all asteroids after collisions
=>when two asteriods meet the smaller one will explode
=>if both of same size then both will explode
=>two asteroids will never explode if they are going in same direction
=> in this ques sign basically shows the direction 

=>the direction it should be towards each other -> <- ... in this way only they are going to be collide

=> if negative - means left <-
=>if positive - means right ->

=>right - left will only collide [+ -]
=>left right will never collide  [- +] never
also 
<-   -> they are going away from each other they will never collide 


Your stack intuition is correct:

Stack mein ab tak ke surviving asteroids honge.
Since we're processing left → right, stack.top() = most recently surviving asteroid.

For every current asteroid:

Collision possible only if:
stack.top() > 0
AND
current < 0




Otherwise, no collision

For example:

[-5, 10]

Stack top is -5, current is +10:

←              →

Moving away → no collision.

Or:

[5, 10]

Both positive → same direction → no collision.

Or:

[-5, -10]

Both negative → same direction → no collision.

🔥 So your base algorithm is:
Process left → right


stack = surviving asteroids


for every current asteroid:


    if collision is possible:
        resolve collision
    else:
        push current

Process left → right

For curr:

    while collision possible:

        if top < abs(curr):
            pop top
            curr survives
            continue

        if top == abs(curr):
            pop top
            curr dies
            break

        if top > abs(curr):
            curr dies
            break

    if curr survived:
        push curr


while = keep resolving collisions as long as the current asteroid is still alive and another collision is possible.

If current survives → push it.
If current dies → break and don't push it.

current comes in
      ↓
alive = true
      ↓
resolve collisions
      ↓
current dies? → alive = false → don't push
      ↓
current survives everything? → alive = true → push
*/


