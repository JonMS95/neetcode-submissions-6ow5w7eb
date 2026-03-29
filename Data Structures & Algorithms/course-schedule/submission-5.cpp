class Solution {
private:
    using vec_int   = std::vector<int>;
    using mat_int   = std::vector<vec_int>;
    using set_int   = std::unordered_set<int>;
    using map_i_si  = std::unordered_map<int, set_int>;

    // Given a number of courses to fulfill and some other courses as prerequisites for each,
    // returns an unordered map where:
    //  ·keys are equal to course id's.
    //  ·values are courses that should be taken beforehand.
    map_i_si _makeHistGraphFromMat(const int num_courses, mat_int& prerequisites)
    {
        map_i_si ret;

        for(int i = 0; i < num_courses; i++)
            ret[i] = {};
        
        for(int i = 0; i < static_cast<int>(prerequisites.size()); i++)
            ret[prerequisites[i][0]].insert(prerequisites[i][1]);
        
        return ret;
    }

    // For a given course, performs a traversal using the graph-as-map and detects whether
    // there's any loop. Note that set of visited nodes should be uniqye per traversal (the
    // one starting from node 0 cannot be reused if not cleared for the latter starting from
    // course 1).
    bool _hasNoLoops(const int course, map_i_si& course_to_reqs_map, set_int& visited_courses)
    {
        // // If current course is standalone, then simply return true.
        // if(!course_to_reqs_map[course].size())
        //     return true;

        // If current course is found within the set of visited nodes, then a loop has been found
        if(visited_courses.count(course))
            return false;

        // Add current course to the set of visited courses.
        visited_courses.insert(course);
        
        // Follow the traversal by jumping to all requirements. If any loop is found, then return false.
        for(int required_course : course_to_reqs_map[course])
            if(!this->_hasNoLoops(required_course, course_to_reqs_map, visited_courses))
                return false;

        visited_courses.erase(course);

        return true;
    }

public:
    bool canFinish(int numCourses, mat_int& prerequisites)
    {
        // Create a structure so as to map courses to other courses that should be taken beforehand.
        map_i_si course_to_requisites = this->_makeHistGraphFromMat(numCourses, prerequisites);

        // Once done so, perform a recursive traversal for each course. If any loop is found, then
        // current course is not doable and false should be returned.
        set_int visited_courses;

        for(int course = 0; course < numCourses; course++)
        {
            // Make sure it contains no nodes from previous traversals.
            visited_courses.clear();

            // If a loop is found for current traversal, exit immediately.
            if(!this->_hasNoLoops(course, course_to_requisites, visited_courses))
                return false;
        }

        return true;
    }
};
