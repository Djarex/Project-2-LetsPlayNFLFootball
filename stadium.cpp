#include "stadium.h"
#include "team.h"
vector<unicorn::Stadium*> unicorn::Stadium::stadiums;
//vector <unicorn::Stadium*> stadiumsPtr  ;

namespace unicorn {

int Stadium::getStadiumId(){
    return stadiumID;

 }

QString Stadium::getTeamsName(){
  QString str="";
    for(auto it = teams.begin();it!= teams.end();++it)
    {
        if(str!=""){str+="<br/>";}
        str+= "<b>Team:</b> "+QString::fromStdString( (*it)->getTeamName());
    }

    return str;

}

 Stadium* Stadium::getStadiumPtrById(int stadiumID){

            for(auto i = stadiums.begin(); i != stadiums.end();++i)
            {
                if(stadiumID == (*i)->getStadiumId())
                {
                    return *i;
                }
            }
            return 0;
}


string Stadium::getStadiumName(){
    return stadiumName;

 }

int Stadium::getStadiumCapacity(){
    return capacity;

 }

string Stadium::getStadiumLocation(){
    return location;

 }

string Stadium::getStadiumConference(){
    return conference;

 }

string Stadium::getStadiumDivision(){
    return division;

 }

string Stadium::getStadiumSurface(){
    return surface;

 }

void Stadium::setStadiumId(int id){
   stadiumID=id;

 }

void Stadium::setStadiumName(string name){
   stadiumName = name;

 }

void Stadium::setStadiumCapacity(int capacity_){
   capacity = capacity_;

 }

void Stadium::setStadiumLocation(string location_){
    location= location_;

 }

void Stadium::setStadiumConference(string conf){
   conference = conf;

 }

void Stadium::setStadiumDivision(string division_){
    division= division_;

 }

void Stadium::setStadiumSurface(string surface_){
   surface=surface_;

 }

void Stadium::initializeStadiums(){




        for(auto it= Team::teams.begin(); it != Team::teams.end();++it)
        {
            stadiums.push_back(it->getTeamStadium());
        }
        //delete [] arr;



        for(auto i = stadiums.begin(); i != stadiums.end();++i)
        {
            vector<Distance*> dist = (*i)->getDistanceFromOthers();
            for( auto  it= dist.begin() ;it!=dist.end();++it  )
            {
                (*it)->OtherStaduimIDPtr = getStadiumPtrById((*it)->OtherStaduimID);

            }

         }












}






}
