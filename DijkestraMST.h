#ifndef DIJKESTRAMST_H
#define DIJKESTRAMST_H
#include "team.h"
namespace unicorn{
class Graph {


    public:
        /**
         * @brief Default constructor
         */
        Graph(int v);

        /**
         * @brief function to reset private members
         */
        void reset();


        /**
         * @brief Function to add edge between two teams
         * @param src: int src stadium vertex
         * @param dest: int dest stadium vertex
         * @param nodeSrc: src stadium object
         * @param nodeDest: dest stadium object
         */
        void addEdge(int src, int dest, Stadium& nodeSrc, Stadium& nodeDest );

        /**
         * @brief Function get stadium
         * @param vertex1: src stadium object
         * @param vertex2: dest stadium object
         * @return stadium object
         */
        Distance* getNodeEdge(int vertex1 , int vertex2);


        /**
         * @brief Function get stadium
         * @param vertex1: src stadium object
         * @param vertex2: dest stadium object
         */
        int* getDist()
        {
            return dist;
        }


        /**
         * @brief Function to check if there is an edge
         * @param vertex1: src stadium object
         * @param vertex2: dest stadium object
         * @return bool
         */
        bool isEdge(int vertex1, int vertex2);

        /**
         * @brief Function to check if all stadiums are visited
         * @return 1 or 0
         */
        int isAllKeyVisited();

        /**
         * @brief Function distances between two vertices
         * @return distance
         */
        int distancFromStartToDest(int dest)
        {
            return dist[dest];
        }


        /**
         * @brief Function to get team of minimum weight
         * @return team object
         */
        Team minKeyVertex(vector<int> vis);


        /**
         * @brief Function distances between two vertices
         * @return distance
         */
        int minKeyDistance(vector<int> vis);



        /**
         * @brief Function distances to print metrix
         */
        void printMatrix();


        /**
         * @brief Function distances between two vertices
         * @return distance
         */
        int minDistance();



        /**
         * @brief Function to print path
         * @return distance
         */
        void printPath(  int vertex1, int vertex2);

        /**
         * @brief Function to construct paths
         */
        void constructPaths(int source);


        /**
         * @brief Function applies dijkstra's algorithm
         * to get shortest distance
         * @param src: starting point
         */
        void dijkstra( int src);

        /**
         * @brief Function helper for determing MST
         * @param src: starting point
         * @param dest: ending point
         * @param inMSt: vector of vertces in MST
         */
        bool createsMST(int src, int dest, vector<bool> inMST);

        /**
         * @brief Function perform calculate MST
         */
        void MST();
        /**
         * @brief Function to print MST
         */
        QString printMST();

private:
        // Number of vertex
            int v;
            // Adjacency matrix
            Stadium ** adj;
            int ** metrix;
            // Mark all the vertices as not visited


            bool *visited;
            path* pathsArr;
            int *dist;
            int *parent;
            vector<PathFromSrcToDest*> pathsToVer;
            vector<Distance*> mstEdges;


};
    // Function to fill the empty adjacency matrix
   Graph::Graph(int v)
    {
        this->v = v;

        adj = new Stadium*[v]();
        visited = new bool[v];
        parent = new int[v];
        dist = new int[v];
        pathsArr = new path[v]();
        metrix = new int*[v-1];



        for (int row = 0; row < v; row++) {
                adj[row] = new Stadium[v]();
                adj[row]->setStadiumId(-1);
                dist[row]= INT_MAX;
                visited[row] = false;
                parent[row]=-1;
                if(row<v-1)
                {
                    metrix[row]= new int[v-1];
                    for(int i=0; i<v-1;i++ )
                    {
                        metrix[row][i] = INT_MAX;
                    }
                }
        }
    }


   int Graph::isAllKeyVisited(){
       for(int i=0; i<v; i++){
           if(!visited[i])
           {
               return false; // not MST yet
               break;
           }
       }
       return true; // MST done

   }


   Team Graph::minKeyVertex(vector<int> vis)
   {
       int min=INT_MAX, minKey;
       for(int i=1;i < v;i++)
       {
           if(dist[i]<min && parent[i]!=-1 && std::find(vis.begin(), vis.end(), i) == vis.end())
           { minKey= i;min = dist[i]; }
       }
       Stadium  st = adj[minKey][minKey];
       Team * tm = *st.getTeams().begin();

       return *tm;
   }



   int Graph::minKeyDistance(vector<int> vis)
   {
       int minDist=INT_MAX;
       for(int i=0;i < v;i++)
       {
           if(dist[i]<minDist && parent[i]!=-1 && std::find(vis.begin(), vis.end(), i) == vis.end())
           { minDist= dist[i];}
       }
       return minDist;
   }


   int Graph::minDistance()
   {
       // Initialize min value
       int min = INT_MAX, min_index;

       for (int i = 1; i < v; i++)
           if (visited[i] == false &&dist[i] <= min)
           {
               min = dist[i];
               min_index = i;
           }

       return min_index;
   }

   void Graph::printPath(  int j, int i)
   {

       if (parent[j] == -1)
           return;
       printPath(parent[j] , i);
       pathsArr[i].paths.push_back(j);

   }


   bool Graph::createsMST(int u, int v, vector<bool> inMST){
      if (u == v)
         return false;
      if (inMST[u] == false && inMST[v] == false)
         return false;
      else if (inMST[u] == true && inMST[v] == true)
         return false;
      return true;
   }

   void Graph::printMatrix()
   {
       string vt ="{";
       for(int i=0;i<v-1;i++)
       {

           vt+="{";
           for(int ii=0;ii<v-1;ii++)
           {
              // cout<<"here"<<endl;

               if( (i+1 != ii+1) && isEdge(i+1,ii+1 ) != 0)
               {
                   int distance = getNodeEdge(i+1,ii+1)->distance;

                    vt+= to_string(distance)+",";
               }
               else
               {
                   vt+="0,";
               }
           }
           vt+="},";
       }
         vt+="}";

        cout<<"matrix: "<<vt<<endl  ;

   }


   QString Graph::printMST()
   {
        QString ss="";
        QString str="";
       int total =0;
       for (auto it = mstEdges.begin(); it != mstEdges.end(); ++it)
       {
           str+="<tr><td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString( (*it)->StadiumIDPtr->getStadiumName() )+"<br/>"+(*it)->StadiumIDPtr->getTeamsName()+"</td><td style=\"text-align:center;valign:middle\">("+QString::number( (*it)->distance)+"M)<br/>&#8594;</td> <td style=\"border:solid 1px #000;width:50%\"><b>Stadium:</b> "+QString::fromStdString((*it)->OtherStaduimIDPtr->getStadiumName())+"<br/>"+(*it)->OtherStaduimIDPtr->getTeamsName()+"</td></tr>";
           total+=(*it)->distance;
       }

       ss="<table cellpadding=\"5\" border=\"0\" cellspacing=\"5\" width=\"100%\" ><h3>DFS Traversal (Total Distance: "+QString::number(total)+" Miles) </h3>";
       return ss+str;
   }


    void Graph::reset()
    {

    pathsToVer.clear();
    mstEdges.clear();
    pathsArr = new path[v]();

    visited = new bool[v];
    parent = new int[v];
    dist = new int[v];

        for (int row = 0; row < v; row++) {
                dist[row]= INT_MAX;
                visited[row] = false;
                parent[row]=-1;
        }
    }

    Distance* Graph::getNodeEdge(int i, int j)
    {
       // int dist=0;
       if( adj[i][j].getStadiumId()!=-1)
       {
            vector<Distance*> vc = adj[i][j].getDistanceFromOthers();
            auto it= vc.begin();
            for(;it != vc.end();++it )
            {
                if( ((*it)->StadiumID == i && (*it)->OtherStaduimID == j) || ((*it)->OtherStaduimID == i && (*it)->StadiumID == j)  )
                {
                    //dist = (*it)->weight;
                    return *it;
                    break;
                }
            }
       }


        return nullptr;

    }




    bool Graph::isEdge(int i, int j) {
        if (i >= 1 && i < v && j >= 1 && j < v)
        {
            if(adj[i][j].getStadiumId()<=0)
            {
                return false;
            }
            else
            {
                return true;
            }

        }
        else{

            return false;
        }
    }






    // Function to add an edge to the graph
    void Graph::addEdge(int src, int dest, Stadium& nodeSrc, Stadium& nodeDest )
    {

        // Considering a bidirectional edge
        adj[src][dest] = nodeDest;
        adj[dest][src] = nodeSrc;
        // diagonal
        adj[src][src] = nodeSrc;
        adj[dest][dest] = nodeDest;
        if(isEdge(src,dest))
        {
             metrix[src-1][dest-1] = getNodeEdge(src,dest)->distance;
        }


    }

    void Graph::MST()
    {

        vector<bool> inMST(v-1, false);
        inMST[0] = true;
        int edgeNo = 0, MSTcost = 0;
        while (edgeNo < v - 2)
        {
           int min = INT_MAX, a = -1, b = -1;
           for (int i = 0; i < v-1; i++) {
              for (int j = 0; j < v-1; j++) {
                 if (metrix[i][j] < min) {
                    if (createsMST(i, j, inMST)) {
                       min = metrix[i][j];
                       a = i;
                       b = j;
                    }
                 }
              }
           }
           if (a != -1 && b != -1) {

               if(isEdge(a+1, b+1))
               {
                   mstEdges.push_back(getNodeEdge(a+1,b+1));
               }
               cout<<"Edge "<<edgeNo++<<" : ("<<a<<" , "<<b<<" ) : cost = "<<min<<endl;
              MSTcost += min;
              inMST[b] = inMST[a] = true;
           }
        }
    }


    // Funtion that implements Dijkstra's shortest path
    void Graph::dijkstra( int src)
    {

        // Distance of source vertex
        dist[src] = 0;


        for (int count = 1; count < v - 1; count++)
        {
            int u= minDistance();;
            // get minimum distance
            // Mark vertex as done
            visited[u] = true;

            for (int i = 1; i < v; i++)
            {

                if(isEdge(u, i)!=0 && i !=u && adj[u][i].getStadiumId()>0)
                {


                    int distance = getNodeEdge(u,i)->distance;
                    //cout<< u <<" - "<<i<< distance <<endl;
                    if (!visited[i]  &&
                        dist[u] + distance  < dist[i])
                    {
                        parent[i] = u;
                        dist[i] = dist[u] + distance ;
                    }
                }
            }

        }


        // build distance array
        constructPaths(src);
        int i=1;
        for(auto it=pathsToVer.begin(); it!= pathsToVer.end();++it)
        {

            if((*it)->end->getStadiumId() != src)
            {
                cout<<"|"<< i <<")"<< (*it)->start->getStadiumName() <<" - " << (*it)->end->getStadiumName()  <<", Total distance:"<< (*it)->totalDistance <<endl<<endl;
                cout<<"    |Edges:"<<endl;

                for(auto it2= (*it)->edges.begin(); it2!= (*it)->edges.end();++it2)
                {
                    cout<<"    |"<<(*it2)->StadiumIDPtr->getStadiumName() <<" - "<< (*it2)->OtherStaduimIDPtr->getStadiumName() << ", cost: "<< (*it2)->distance<<endl;
                }
                cout<<endl;
            }
        i++;
        }
    }


    void Graph::constructPaths(int source)
    {
        //cout<< "vvvv"<<<<endl;
        int src = source;

        for (int i = 1; i < v; i++)
        {
           //cout<< i << " "<<dist[i]<<endl;
            pathsArr[i].distance = dist[i];
            pathsArr[i].paths.push_back(src);
             printPath( i,i);

        }



        for (int i = 1; i < v; i++)
        {

            PathFromSrcToDest * pa = new PathFromSrcToDest;
            pa->totalDistance = pathsArr[i].distance;
                Distance * ed2 = new Distance;

            for(int ii = 0; ii< (int)pathsArr[i].paths.size();ii++ )
            {


                if( (ii+1)< (int)pathsArr[i].paths.size())
                {

                        if( pathsArr[i].paths[ii] !=0 && pathsArr[i].paths[ii+1]!=0&& isEdge(pathsArr[i].paths[ii], pathsArr[i].paths[ii+1])!=0)
                        {
                            Distance * ed = getNodeEdge(pathsArr[i].paths[ii], pathsArr[i].paths[ii+1]);
                            pa->edges.push_back(ed);

                            if(ii==0 &&ed->StadiumID>0 && ed->StadiumID== pathsArr[i].paths[ii] ){pa->start = ed->StadiumIDPtr;}
                            if(ii==0 &&ed->StadiumID>0 && ed->OtherStaduimID== pathsArr[i].paths[ii] ){pa->start = ed->OtherStaduimIDPtr;}

                            ed2 = ed;

                        }

                }

                if((ii+1) == (int)pathsArr[i].paths.size() &&ed2->StadiumID>0 && ed2->StadiumID== pathsArr[i].paths[ii] )
                {

                    pa->end = ed2->StadiumIDPtr;
                    //cout<< "||||"<< pa->start->getStadiumId()<<","<<pa->end->getStadiumId()<<endl;
                     pathsToVer.push_back(pa);

                }
                if( (ii+1) == (int)pathsArr[i].paths.size()&&ed2->StadiumID>0  && ed2->OtherStaduimID== pathsArr[i].paths[ii] ){
                    pa->end = ed2->OtherStaduimIDPtr;

                    //cout<< "||||"<< pa->start->getStadiumId()<<","<<pa->end->getStadiumId()<<endl;
                     pathsToVer.push_back(pa);

                }
// cout<<"|||" <<pa->end->getStadiumId()<<endl;

            }


        }

    }




};


#endif // DIJKESTRAMST_H


//{{0,0,0,0,0,0,0,0,870,580,0,0,1115,0,0,0,0,372,0,0,0,0,0,0,0,0,0,650,0,0,0,0},
//    {0,0,0,0,225,0,375,0,740,0,0,0,0,0,0,0,0,0,0,600,0,0,425,0,0,0,0,0,0,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,80,0,0,0,0,0,90},
//    {0,0,0,0,0,0,0,0,0,0,210,430,0,0,0,0,0,0,0,0,0,429,0,0,0,0,225,0,2070,0,0,0},
//    {0,225,0,0,0,0,0,0,0,0,0,0,0,0,342,0,0,0,0,0,0,0,0,0,0,0,365,0,0,0,0,340},
//    {0,0,0,0,0,0,0,0,0,0,0,80,0,50,0,415,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,375,0,0,0,0,0,225,0,0,0,0,0,250,0,0,0,0,0,0,0,0,0,0,0,0,260,0,0,0,240,0},
//    {0,0,0,0,0,0,225,0,0,0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,115,0,0,0,0,0},
//    {870,740,0,0,0,0,0,0,0,650,0,0,230,0,0,460,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {580,0,0,0,0,0,0,0,650,0,0,0,0,0,0,560,0,1015,0,0,0,0,0,0,0,0,0,930,0,0,0,0},
//    {0,0,0,210,0,0,0,90,0,0,0,0,0,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,430,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,300,0,0,0,0,0,0,0,0,0,0,0},
//    {1115,0,0,0,0,0,0,0,230,0,0,0,0,0,0,0,0,0,0,965,0,0,320,0,0,0,0,0,0,0,670,0},
//    {0,0,0,0,0,50,250,0,0,0,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,0,342,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,0,0,0,0,0,0,0,0,0,170,0,0},
//    {0,0,0,0,0,415,0,0,460,560,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,470,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,270,0,0,0,0,0,0,0,0,569,1270,0,0,0},
//    {372,0,0,0,0,0,0,0,0,1015,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,270,15,0,0,1500,0,0,0,0,0,0,200,0,0,0,0},
//    {0,600,0,0,0,0,0,0,0,0,0,0,965,0,315,0,0,0,0,0,0,1255,0,0,0,0,0,0,0,210,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,300,0,0,0,0,0,0,1500,0,0,0,0,0,0,0,0,0,1390,0,700,0},
//    {0,0,0,429,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1255,0,0,0,195,195,0,0,0,0,0,0,0},
//    {0,425,0,0,0,0,0,0,0,0,0,0,320,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,480,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,0,0,50,0,0,0,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,195,0,0,0,50,0,0,0,0,0,0},
//    {0,0,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,50,0,315,0,0,0,0,0},
//    {0,0,0,225,365,0,260,115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,0,0,0,0,0,0},
//    {650,0,0,0,0,0,0,0,0,930,0,0,0,0,0,0,569,0,200,0,0,0,0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,2070,0,0,0,0,0,0,0,0,0,0,0,0,1275,0,0,0,1390,0,0,0,0,0,0,0,0,0,0,0},
//    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,170,0,0,0,0,210,0,0,480,0,0,0,0,0,0,0,0,0},
//    {0,0,0,0,0,0,240,0,0,0,0,0,670,0,0,470,0,0,0,0,700,0,0,0,0,0,0,0,0,0,0,0},
//        {0,0,90,0,340,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}
