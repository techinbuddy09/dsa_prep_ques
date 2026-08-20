class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;//to prevent overflow as the mass  it will grow in size
        for(int ast :asteroids)
        {
            if(m < ast)
            {
                return false;//means the planet is only destryed =>asteroued cant be destroyed
            }
            // if not means can be destroyed and its weight keep on growing the mass of the planet
            m+=ast;
        }
        // in end if all the asteroid desroyed 
        return true;
        
    }
};
/*see one observation we can get from here is that if the mass of the planet(m) is >= mass of the asteroid => then what happens is that asteroid is destroyed and that mass of that asteroid is gained by planet means added in it ....

if not the planet it is only destroyed

sort asteroids
      ↓
smallest → largest
      ↓
mass >= asteroid?
   ↓ yes
destroy + absorb mass
      ↓
mass increases
      ↓
next asteroid
*/