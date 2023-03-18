class BrowserHistory {
    stack<string> backwardLinks, forwardLinks;
    string curr;
public:
    BrowserHistory(string homepage) {
        curr = homepage;
    }
    
    void visit(string url) {
        while(forwardLinks.size())
            forwardLinks.pop();
        backwardLinks.push(curr);
        curr = url;
    }
    
    string back(int steps) {
        while(steps-- && !backwardLinks.empty())
        {
            forwardLinks.push(curr);
            curr = backwardLinks.top();
            backwardLinks.pop();
        }
        return curr;
    }
    
    string forward(int steps) {
        while(steps-- && !forwardLinks.empty())
        {
            backwardLinks.push(curr);
            curr = forwardLinks.top();
            forwardLinks.pop();
        }
        return curr;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */