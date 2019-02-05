 var nano = require('nano-blue')('http://couchadmin:test@localhost:5984');
 
let maindb = nano.use('pg_collection_retail_maindb');

 
function getAllDocsByType() {
    let db = maindb;
var type = 'item';
var params = {         
startkey: type + '_',
endkey: type + '_z',        
include_docs: true
};
return db.fetch({}, params).spread(function(body, header) {
console.log("spread hello");
console.log(body)       
let resp = [];       
 return resp;  
}).catch(function(err) {
         console.log(err);
throw 'Fatal! Not expected to come here. This API doesnt throw any error';
     
});
 
};
 getAllDocsByType()

 async function getDoc(id, db, errMsg, bDontThrow, param) {
    var response = respJsonUtil.get();
    param = param ? param : {};
    try {
        let queryResp = await db.get(id, param);
        return queryResp[0];
    } catch (err) {
        if (errMsg && errMsg.indexOf(err.reason) >= 0) {
            //Reason is expected so no problem
        } else if (['missing', 'deleted'].indexOf(err.reason) === -1) {
            logger.error(err); //404 Not Found is expected. Other errors are dangerous
        }
        if (errMsg === 'propagate') {
            throw err;
        }

        if (!errMsg) { //Maintaining the old response foramt
            errMsg = 'getDoc error ' + id;
            logger.error(errMsg);

            response.msg = errMsg;
            response.err.msg = errMsg;
            response.err.errObj = err;
            return response;
        } else {
            if (bDontThrow) {
                return errMsg;
            } else {
                throw errMsg;
            }
        }
    }
};
