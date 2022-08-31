class Offspring: public Alien {
public:
    //operator overloading 
    Offspring operator+(const Offspring& x) {
      Offspring offspring;
      offspring.weight = this->weight + x.weight;
      offspring.height = this->height + x.height;
      offspring.prestige = this->prestige + x.prestige;
      return offspring;
    }

    //override
    float getWeight(float weight){
      this->weight = weight/2;        //sum of parents’ weights)/2
      return this->weight;
    }

    float getHeight(float height){
      this->height = height/2;        //sum of parents’ heights)/2
      return this->height;
    }

    float getPrestige(float prestige){
      this->prestige = prestige/2;     //sum of parents’ prestiges)/2
      return this->prestige;
    }
};

