#include <cstdio>
#include <vector>
using namespace std;

const int dify[] = {0,-1,0,1,0};
const int difx[] = {0,0,-1,0,1};

struct point{
	point(){}
	point(int y,int x):y(y),x(x){}
	int x,y;
};

int R,C,N;

int main(){
	// freopen("in","r",stdin);
	int test = 0;
	while(scanf("%d %d %d",&R,&C,&N) == 3){
		if(R+C+N == 0) break;
		vector <struct point> V;
		V.clear();
		for(int i=1;i<=N;i++){
			int rr,cc;
			scanf("%d %d",&rr,&cc);
			V.push_back(point(rr,cc));
		}
		int rr,cc;
		scanf("%d %d",&rr,&cc);
		bool pass1 = true, pass2 = true;
		for(int i=0;i<5;i++){
			if(rr+dify[i] >= 0 and rr+dify[i] < R and cc+difx[i] >= 0 and cc+difx[i] < C){
				pass2 = true;
				for(int j=0;j<N;j++) if(V[j].y == rr+dify[i] or V[j].x == cc+difx[i]){
					pass2 = false;
					break;
				}
				if(pass2) break;
			}
			if(i == 4 and pass2 == false) pass1 = false;
		}
		if(pass1) printf("Case %d: Escaped again! More 2D grid problems!\n",++test);
		else printf("Case %d: Party time! Let's find a restaurant!\n",++test);
	}
	return 0;
}